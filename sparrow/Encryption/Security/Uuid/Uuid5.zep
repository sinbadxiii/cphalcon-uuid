namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;

class Uuid5 extends Uuid
{
    const TYPE = 5;

    public function __construct(<Uuid> ns, string name)
    {
         var hash;
         let hash = sha1(hex2bin(str_replace("-", "", ns->uid)) . name);

         let this->uid = this->format(hash, self::TYPE);
    }
}