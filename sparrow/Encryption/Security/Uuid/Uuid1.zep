namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;
use \DateTimeImmutable;
use \DateTimeInterface;

class Uuid1 extends Uuid implements TimeBasedUidInterface
{
    const TYPE = 1;

    private static clockSeq;

    public function __construct(<DateTimeInterface> time = null, var node = null)
    {
        if time === null {
            let time = new DateTimeImmutable();
        }

        let time = this->dateTimeToHex(time);

        let self::clockSeq = this->number(0x3FFF);

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
            substr(time, -15, 3), self::clockSeq | 0x8000, node
        );
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