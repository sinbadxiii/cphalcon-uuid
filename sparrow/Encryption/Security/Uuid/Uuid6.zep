namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;
use \DateTimeImmutable;

class Uuid6 extends Uuid implements TimeBasedUidInterface
{
    const TYPE = 6;

    private static node;

    public function __construct(string uuid = null)
    {
        let this->uid = uuid;
    }

    public function getDateTime() -> <DateTimeImmutable>
    {
        return this->hexToDateTime(
            "0" . substr(this->uid, 0, 8) .
            substr(this->uid, 9, 4) . substr(this->uid, 15, 3)
        );
    }

    public function getNode() -> string
    {
        return substr(this->uid, 24);
    }
}