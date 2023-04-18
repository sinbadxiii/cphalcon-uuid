namespace Sparrow\Encryption\Security\Uuid;

class SysNodeProvider implements NodeProviderInterface
{
     const IFCONFIG_PATTERN = "/[^:]([0-9a-f]{2}([:-])[0-9a-f]{2}(\2[0-9a-f]{2}){4})[^:]/i";

     public function getNode() -> string
      {
          var node, mac, phpOs;

          let phpOs = constant("PHP_OS");

           if strtoupper(phpOs) === "LINUX" {
              var addressPaths;
              let addressPaths = glob("/sys/class/net/*/address", GLOB_NOSORT);

              if addressPaths === false || count(addressPaths) === 0 {
                let node = "";
              } else {
                var macs = [];
                var addressPath;

                for addressPath in addressPaths {
                    if is_readable(addressPath) {
                        let macs[] = file_get_contents(addressPath);
                    }
                }

                let macs = array_map("trim", macs);

                let macs = array_filter(macs, function (string address) {
                    return address !== "00:00:00:00:00:00" && preg_match(
                    "/^([0-9a-f]{2}:){5}[0-9a-f]{2}$/i", address);
                });

                let mac = reset(macs);
                let node = (string) mac;
              }
          }

          if node === "" {
              var disabledFunctions;

              let disabledFunctions = strtolower((string) ini_get("disable_functions"));

              if str_contains(disabledFunctions, "passthru") {
                  let node = "";
              }

              ob_start();
              switch (strtoupper(substr(phpOs, 0, 3))) {
                  case "WIN":
                      passthru("ipconfig /all 2>&1");
                      break;
                  case "DAR":
                      passthru("ifconfig 2>&1");
                      break;
                  case "FRE":
                      passthru("netstat -i -f link 2>&1");
                      break;
                  case "LIN":
                  default:
                      passthru("netstat -ie 2>&1");
                      break;
              }

              var ifconfig, iface, matches;

              let ifconfig = (string) ob_get_clean();

              if (preg_match_all(self::IFCONFIG_PATTERN, ifconfig, matches, PREG_PATTERN_ORDER)) {
                  for  iface in matches[1] {
                      if (iface !== "00:00:00:00:00:00" && iface !== "00-00-00-00-00-00") {
                          let node = iface;
                      }
                  }
              }
          }

          let node = str_replace([":", "-"], "", node);

          return node;
      }
}
