namespace Sparrow\Encryption\Security\Uuid;

use \DateTimeImmutable;

interface TimeBasedUidInterface
{
    public function getDateTime() -> <DateTimeImmutable>;
}
