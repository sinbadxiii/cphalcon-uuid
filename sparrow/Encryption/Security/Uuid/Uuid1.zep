namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;
use \DateTimeImmutable;

class Uuid1 extends Uuid implements TimeBasedUidInterface
{
    const TYPE = 1;

    private static clockSeq;

    public function __construct(string uuid = null, var node = null)
    {
        if uuid === null {
            var time;
            let time = microtime(false);
            let time = substr(time, 11) . substr(time, 2, 7);

            let time = str_pad(dechex(time + self::TIME_OFFSET_INT), 16, "0", STR_PAD_LEFT);

            var clockSeq;
            let clockSeq = this->number(0x3FFF);

            if node === null {
                if (function_exists("apcu_fetch")) {
                    let node = apcu_fetch("__phalcon_uuid_node");
                    if false === node {
                        let node = this->getNodeProvider()->getNode();
                        apcu_store("__phalcon_uuid_node", node);
                    }
                } else {
                    let node = this->getNodeProvider()->getNode();
                }
            }

            let this->uid = sprintf(
                "%08s-%04s-1%03s-%04x-%012s",
                substr(time, -8), substr(time, -12, 4),
                substr(time, -15, 3), clockSeq | 0x8000, node
            );
        } else {
            let this->uid = uuid;
        }
    }

    public function getDateTime() -> <DateTimeImmutable>
    {
        return this->hexToDateTime(
            "0" . substr(this->uid, 15, 3) .
            substr(this->uid, 9, 4) . substr(this->uid, 0, 8)
        );
    }

    public function getNode() -> string
    {
        return this->mac(this->uid);
    }
}