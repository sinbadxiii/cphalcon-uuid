
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Sparrow_Encryption_Crypt_Padding_PadInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Sparrow\\Encryption\\Crypt\\Padding, PadInterface, sparrow, encryption_crypt_padding_padinterface, sparrow_encryption_crypt_padding_padinterface_method_entry);

	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Sparrow_Encryption_Crypt_Padding_PadInterface, pad);
/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Sparrow_Encryption_Crypt_Padding_PadInterface, unpad);
