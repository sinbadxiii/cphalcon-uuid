namespace Sparrow\Encryption\Security;

use ValueError;
use \DateTimeImmutable;
use \InvalidArgumentException;
use Sparrow\Encryption\Security\Uuid\Uuid1;
use Sparrow\Encryption\Security\Uuid\Uuid3;
use Sparrow\Encryption\Security\Uuid\Uuid4;
use Sparrow\Encryption\Security\Uuid\Uuid5;
use Sparrow\Encryption\Security\Uuid\Uuid6;
use Sparrow\Encryption\Security\Uuid\SysNodeProvider;
use Sparrow\Encryption\Security\Uuid\NodeProviderInterface;

class Uuid extends BinaryBase
{
    const TIME_OFFSET_INT = 0x01B21DD213814000;
    const TIME_OFFSET_BIN = "\x01\xb2\x1d\xd2\x13\x81\x40\x00";

    const NIL = "00000000-0000-0000-0000-000000000000";
    const MAX = "ffffffff-ffff-ffff-ffff-ffffffffffff";

    const NAMESPACE_DNS = "6ba7b810-9dad-11d1-80b4-00c04fd430c8";
    const NAMESPACE_URL = "6ba7b811-9dad-11d1-80b4-00c04fd430c8";
    const NAMESPACE_OID = "6ba7b812-9dad-11d1-80b4-00c04fd430c8";
    const NAMESPACE_X500 = "6ba7b814-9dad-11d1-80b4-00c04fd430c8";

    protected uid;

    public static function mac(string uuid) -> string | null
    {
        var reUuid;

        let reUuid = self::toString(uuid);
        if !is_string(reUuid) {
            trigger_error(sprintf("mac() expects parameter 1 to be string, %s given", gettype(reUuid)), E_USER_WARNING);

            return null;
        }

        var parsed;

        let parsed = self::parse(reUuid);

        if Uuid1::TYPE !== parsed["version"] {
            if (80000 > PHP_VERSION_ID) {
                return null;
            }

            throw new ValueError("mac(): Argument #1 ($uuid) UUID DCE TIME expected");
        }

        return strtr(parsed["node"], "ABCDEF", "abcdef");
    }

    final public static function v1(string uuid = null) -> <Uuid1>
    {
        return new Uuid1(uuid);
    }

    final public static function v3(var ns, string name) -> <Uuid>
    {
        return new Uuid3(ns, name);
    }

    final public static function v4() -> <Uuid>
    {
        return new Uuid4();
    }

    final public static function v5(var ns, string name) -> <Uuid>
    {
        return new Uuid5(ns, name);
    }

    final public static function v6() -> <Uuid>
    {
        return new Uuid6();
    }

    private static function parse(var uuid) -> array | null
    {
        var matches;

        if !preg_match("{^(?<time_low>[0-9a-f]{8})-(?<time_mid>[0-9a-f]{4})-(?<version>[0-9a-f])(?<time_hi>[0-9a-f]{3})-(?<clock_seq>[0-9a-f]{4})-(?<node>[0-9a-f]{12})$}Di", uuid, matches) {
            return null;
        }

        return [
            "time": "0" . matches["time_hi"] . matches["time_mid"] . matches["time_low"],
            "version": hexdec(matches["version"]),
            "clock_seq": hexdec(matches["clock_seq"]),
            "node": matches["node"]
        ];
    }

    protected function format(string hash, int version) -> string
    {
        return sprintf("%08s-%04s-%04x-%04x-%012s",
            substr(hash, 0, 8),
            substr(hash, 8, 4),
            (hexdec(substr(hash, 12, 4)) & 0x0fff) | version << 12,
            (hexdec(substr(hash, 16, 4)) & 0x3fff) | 0x8000,
            substr(hash, 20, 12)
        );
    }

    protected function hexToDateTime(var time) -> <DateTimeImmutable>
    {
       let time = hexdec(time) - self::TIME_OFFSET_INT;
       let time = strval(time);

       if 9 > strlen(time) {
           let time = "-" === time[0] ? "-" . str_pad(substr(time, 1), 8, "0", STR_PAD_LEFT) : str_pad(time, 8, "0", STR_PAD_LEFT);
       }

       return DateTimeImmutable::createFromFormat("U.u?", substr_replace(time, ".", -7, 0));
    }

    private static function toString(var value)
    {
        if (is_string(value) || null === value || (is_object(value) ? method_exists(value, "__toString") : is_scalar(value))) {
            return (string) value;
        }

        return value;
    }

    public function getNodeProvider()
    {
        return new SysNodeProvider();
    }

    public function __toString() -> string
    {
        return this->uid;
    }

    public function jsonSerialize() -> string
    {
        return this->uid;
    }
}