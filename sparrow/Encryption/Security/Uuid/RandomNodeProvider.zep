namespace Sparrow\Encryption\Security\Uuid;

class RandomNodeProvider implements NodeProviderInterface
{
    public function getNode() -> string
    {
        var node, seed;

        let seed = this->getSeed();

        let node = sprintf("%06x%06x",
            seed[0] | 0x010000, seed[1]
        );

        return node;
    }

    public function getSeed() -> array
    {
        array seed;

        let seed = [
            random_int(0, 0xFFFFFF),
            random_int(0, 0xFFFFFF)
        ];

        return seed;
    }
}
