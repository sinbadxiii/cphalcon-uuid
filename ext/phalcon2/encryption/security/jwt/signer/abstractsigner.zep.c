
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Abstract class helping with the signer classes
 */
ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_JWT_Signer_AbstractSigner)
{
	ZEPHIR_REGISTER_CLASS(Phalcon2\\Encryption\\Security\\JWT\\Signer, AbstractSigner, phalcon2, encryption_security_jwt_signer_abstractsigner, phalcon2_encryption_security_jwt_signer_abstractsigner_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon2_encryption_security_jwt_signer_abstractsigner_ce, SL("algorithm"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon2_encryption_security_jwt_signer_abstractsigner_ce, 1, phalcon2_encryption_security_jwt_signer_signerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon2_Encryption_Security_JWT_Signer_AbstractSigner, getAlgorithm)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "algorithm");
}

