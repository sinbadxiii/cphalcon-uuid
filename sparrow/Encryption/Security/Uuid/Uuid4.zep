namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;

class Uuid4 extends Uuid
{
    const TYPE = 4;

    public function __construct(string uuid = null)
    {
        if uuid === null  {
            var hash;
            let hash = bin2hex(this->bytes(16));

            let this->uid = this->format(hash, self::TYPE);
        } else {
            let this->uid = uuid;
        }
    }
}