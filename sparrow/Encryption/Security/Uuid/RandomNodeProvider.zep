namespace Sparrow\Encryption\Security\Uuid;

class RandomNodeProvider implements NodeProviderInterface
{
     public function getNode() -> string
      {
          var node;

          let node = sprintf("%06x%06x",
              random_int(0, 0xFFFFFF) | 0x010000,
              random_int(0, 0xFFFFFF)
          );

          return node;
      }
}
