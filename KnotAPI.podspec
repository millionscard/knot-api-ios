Pod::Spec.new do |s|
  s.name          = "KnotAPI"
  s.version       = "2.0.0"
  s.summary       = "Connect to your customers online accounts easily"
  s.description   = "Change Card on File Information, Cancel Subscriptions, Change Passwords, and more via Knot."
  s.homepage      = "https://www.knotapi.com/"
  s.license       = "MIT"
  s.author        = "Tarik"
  s.platform      = :ios, "14.0"
  s.swift_version = "5.0"
  s.source        = { :git => "https://github.com/millionscard/knot-api-ios.git", :tag => "#{s.version}" }
  s.vendored_frameworks = "KnotAPI.xcframework"

  # Build-time version warnings (CocoaPods-only).
  # IMPORTANT: Use /bin/sh for maximal CocoaPods compatibility; run Ruby via heredoc.
  s.script_phase = {
    :name => "Knot SDK Version Warning",
    :execution_position => :before_compile,
    :shell_path => "/bin/sh",
    :output_files => ["$(DERIVED_FILE_DIR)/knot-sdk-version-check-complete.txt"],
    :script => <<-'SCRIPT'
set +e

# Kill switch
if [ "${KNOT_SDK_VERSION_WARNING_DISABLED}" = "1" ]; then
  exit 0
fi

/usr/bin/env ruby <<'RUBY'
# encoding: utf-8
begin
  require 'json'
  require 'net/http'
  require 'uri'
  require 'timeout'

  # Exit silently if disabled
  if ENV['KNOT_SDK_VERSION_WARNING_DISABLED'] == '1'
    exit 0
  end

  # Normalize version string:
  # - strip leading v
  # - drop build metadata (+...)
  # - drop prerelease (-...)
  # - normalize x.y -> x.y.0
  def normalize_version(version)
    v = version.to_s.strip
    v = v.sub(/^v/i, '')
    v = v.split('+').first
    v = v.split('-').first

    if v.match?(/^\d+\.\d+$/)
      v = "#{v}.0"
    end

    v
  end

  def valid_semver?(version)
    v = normalize_version(version)
    v.match?(/^\d+\.\d+\.\d+$/)
  end

  # Extract PODS section from Podfile.lock
  def extract_pods_section(lock_contents)
    # Matches:
    # PODS:
    #   - Foo (1.0.0)
    #   ...
    # <NEXT_SECTION>:
    #
    m = lock_contents.match(/^PODS:\n(?<body>.*?)(^\S.*?:\n|\z)/m)
    m ? ("PODS:\n" + m[:body]) : nil
  end

  # Parse Podfile.lock to get installed version
  def get_installed_version
    candidates = []

    if ENV['PODS_PODFILE_DIR_PATH'] && !ENV['PODS_PODFILE_DIR_PATH'].to_s.empty?
      candidates << File.join(ENV['PODS_PODFILE_DIR_PATH'], 'Podfile.lock')
    end

    # Fallback attempts (best-effort; silent failures)
    candidates.concat([
      File.expand_path('Podfile.lock', Dir.pwd),
      File.expand_path('../Podfile.lock', Dir.pwd),
      File.expand_path('../../Podfile.lock', Dir.pwd)
    ])

    lock_path = candidates.find { |p| p && File.exist?(p) }
    unless lock_path
      return nil
    end

    content = File.read(lock_path)
    pods_section = extract_pods_section(content)
    unless pods_section
      return nil
    end

    # Prefer root pod entry if present
    # Typical lines are indented: "  - KnotAPI (1.0.0)" or "  - KnotAPI/Subspec (1.0.0)"
    # 1) Try root KnotAPI
    if (m = pods_section.match(/^\s*-\s+KnotAPI\s+\(([^)]+)\)/))
      v = normalize_version(m[1])
      return v if valid_semver?(v)
    end

    # 2) Fallback to subspec if root not found
    if (m = pods_section.match(/^\s*-\s+KnotAPI\/[^\s]+\s+\(([^)]+)\)/))
      v = normalize_version(m[1])
      return v if valid_semver?(v)
    end

    nil
  rescue => e
    nil
  end

  # Fetch version warning message from Knot API endpoint
  def fetch_version_warning_message(installed_version)
    return nil unless installed_version && valid_semver?(installed_version)

    uri = URI("https://production.knotapi.com/sdk/version-check?currentVersion=#{installed_version}&platform=ios")

    begin
      Timeout.timeout(2) do
        http = Net::HTTP.new(uri.host, uri.port)
        http.use_ssl = true
        http.open_timeout = 2
        http.read_timeout = 2

        req = Net::HTTP::Get.new(uri)
        req['User-Agent'] = 'KnotSDKVersionCheck'

        resp = http.request(req)
        return nil unless resp.code == '200'

        data = JSON.parse(resp.body)
        message = data['message']
        return message if message && !message.to_s.strip.empty?
      end
    rescue
      # Silent failure
    end

    nil
  end

  installed_version = get_installed_version
  unless installed_version && valid_semver?(installed_version)
    exit 0
  end

  warning_message = fetch_version_warning_message(installed_version)
  if warning_message && !warning_message.to_s.strip.empty?
    $stderr.puts "warning: #{warning_message}"
  end

rescue => e
  exit 0
end
RUBY

# Create output marker file (with error handling to prevent build failures)
# Use $DERIVED_FILE_DIR directly (it's an environment variable set by Xcode)
if [ -n "$DERIVED_FILE_DIR" ]; then
  OUTPUT_FILE="$DERIVED_FILE_DIR/knot-sdk-version-check-complete.txt"
  mkdir -p "$DERIVED_FILE_DIR" 2>/dev/null || true
  echo "checked" > "$OUTPUT_FILE" 2>/dev/null || true
fi

exit 0
    SCRIPT
  }
end
