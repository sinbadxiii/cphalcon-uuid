namespace Sparrow\Encryption\Security\Uuid;

use \DateTimeImmutable;

interface NodeProviderInterface
{
    public function getNode() -> string;
}
