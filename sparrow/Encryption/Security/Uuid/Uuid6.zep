namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;
use \DateTimeImmutable;
use \DateTimeInterface;

class Uuid6 extends Uuid implements TimeBasedUidInterface
{
    const TYPE = 6;

    private static node;

    public function __construct(<DateTimeInterface> time = null, var node = null)
    {
        var uuid1, uuid;
        let uuid1 = (string) new Uuid1(time, node);

        let uuid = substr(uuid1, 15, 3).substr(uuid1, 9, 4).substr(uuid1, 0, 1)."-".substr(uuid1, 1, 4)."-6".substr(uuid1, 5, 3).substr(uuid1, 18, 6);

        if node !== null {
            let this->uid = uuid . substr(uuid1, 24);
        } else {
          //class Uuid1() returns a stable "node" that can leak the MAC of the host, but
          //class Uuid6 prefers a truly random number here, let's XOR both to preserve the entropy
            if self::node === null {
                var seed;

                let seed = (new RandomNodeProvider())->getSeed();
                let node = unpack("N2", hex2bin("00" . substr(uuid1, 24, 6)) . hex2bin("00" . substr(uuid1, 30)));
                let self::node = sprintf("%06x%06x", (seed[0] ^ node[1]) | 0x010000, seed[1] ^ node[2]);
            }

            let this->uid = uuid . self::node;
        }
    }

    public function getDateTime() -> <DateTimeImmutable>
    {
        return this->hexToDateTime("0" . substr(this->uid, 0, 8) .
            substr(this->uid, 9, 4) . substr(this->uid, 15, 3)
        );
    }

    public function getNode() -> string
    {
        return substr(this->uid, 24);
    }
}