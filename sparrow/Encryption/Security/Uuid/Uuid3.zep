namespace Sparrow\Encryption\Security\Uuid;

use Sparrow\Encryption\Security\Uuid;

class Uuid3 extends Uuid
{
    const TYPE = 3;

    public function __construct(<Uuid> ns, string name)
    {
         var hash;
         let hash = md5(hex2bin(str_replace("-", "", ns->uid)) . name);

         let this->uid = this->format(hash, self::TYPE);
    }
}