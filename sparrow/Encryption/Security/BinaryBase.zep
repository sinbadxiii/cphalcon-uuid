
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Sparrow\Encryption\Security;

class BinaryBase
{
    /**
     * Generates a random base58 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The result may contain alphanumeric characters except 0, O, I and l.
     *
     * It is similar to `Phalcon\Encryption\Security\Random::base64()` but has been
     * modified to avoid both non-alphanumeric characters and letters which
     * might look ambiguous when printed.
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->base58(); // 4kUgL2pdQMSCQtjE
     *```
     *
     * @see    \Phalcon\Encryption\Security\Random:base64
     * @link   https://en.wikipedia.org/wiki/Base58
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function base58(int len = null) -> string
    {
        return this->base(
            "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz",
            58,
            len
        );
    }

    /**
     * Generates a random base62 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     *
     * It is similar to `Phalcon\Encryption\Security\Random::base58()` but has been
     * modified to provide the largest value that can safely be used in URLs
     * without needing to take extra characters into consideration because it is
     * [A-Za-z0-9].
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->base62(); // z0RkwHfh8ErDM1xw
     *```
     *
     * @see    \Phalcon\Encryption\Security\Random:base58
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function base62(int len = null) -> string
    {
        return this->base(
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
            62,
            len
        );
    }

    /**
     * Generates a random base64 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     * Size formula: 4 * ($len / 3) rounded up to a multiple of 4.
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->base64(12); // 3rcq39QzGK9fUqh8
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function base64(int len = null) -> string
    {
        return base64_encode(
            this->bytes(len)
        );
    }

    /**
     * Generates a random URL-safe base64 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     *
     * By default, padding is not generated because "=" may be used as a URL
     * delimiter. The result may contain A-Z, a-z, 0-9, "-" and "_". "=" is also
     * used if $padding is true. See RFC 3548 for the definition of URL-safe
     * base64.
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
     *```
     *
     * @link https://www.ietf.org/rfc/rfc3548.txt
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function base64Safe(int len = null, bool padding = false) -> string
    {
        var s;

        let s = strtr(
            base64_encode(
                this->base64(len)
            ),
            "+/",
            "-_"
        );

        let s = preg_replace(
            "#[^a-z0-9_=-]+#i",
            "",
            s
        );

        if !padding {
            return rtrim(s, "=");
        }

        return s;
    }

    /**
     * Generates a random binary string
     *
     * The `Random::bytes` method returns a string and accepts as input an int
     * representing the length in bytes to be returned.
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The result may contain any byte: "x00" - "xFF".
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * $bytes = $random->bytes();
     * var_dump(bin2hex($bytes));
     * // Possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function bytes(int len = 16) -> string
    {
        if len <= 0 {
            let len = 16;
        }

        return random_bytes(len);
    }

    /**
     * Generates a random hex string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->hex(10); // a29f470508d5ccb8e289
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    public function hex(int len = null) -> string
    {
        return array_shift(
            unpack(
                "H*",
                this->bytes(len)
            )
        );
    }

    /**
     * Generates a random number between 0 and $len
     *
     * Returns an integer: 0 <= result <= $len.
     *
     *```php
     * $random = new \Phalcon\Encryption\Security\Random();
     *
     * echo $random->number(16); // 8
     *```
     * @throws Exception If secure random number generator is not available,
     *                   unexpected partial read or $len <= 0
     */
    public function number(int len) -> int
    {
        if unlikely len <= 0 {
            throw new Exception("Input number must be a positive integer");
        }

        return random_int(0, len);
    }

    /**
     * Generates a random string based on the number ($base) of characters
     * ($alphabet).
     *
     * If $n is not specified, 16 is assumed. It may be larger in future.
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    protected function base(string alphabet, int base, n = null) -> string
    {
        var bytes, idx;
        string byteString = "";

        let bytes = unpack(
            "C*",
            this->bytes(n)
        );

        for idx in bytes {
            let idx = idx % 64;

            if idx >= base {
                let idx = this->number(base - 1);
            }

            let byteString .= alphabet[(int) idx];
        }

        return byteString;
    }
}
