
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_Uuid_RandomNodeProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon2\\Encryption\\Security\\Uuid, RandomNodeProvider, phalcon2, encryption_security_uuid_randomnodeprovider, phalcon2_encryption_security_uuid_randomnodeprovider_method_entry, 0);

	zend_class_implements(phalcon2_encryption_security_uuid_randomnodeprovider_ce, 1, phalcon2_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon2_Encryption_Security_Uuid_RandomNodeProvider, getNode)
{
	zval node, _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0xFFFFFF);
	ZEPHIR_CALL_FUNCTION(&_2, "random_int", NULL, 7, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0xFFFFFF);
	ZEPHIR_CALL_FUNCTION(&_3, "random_int", NULL, 7, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "%06x%06x");
	ZVAL_LONG(&_0, ((int) (zephir_get_numberval(&_2)) | 0x010000));
	ZEPHIR_CALL_FUNCTION(&node, "sprintf", NULL, 9, &_4, &_0, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(&node);
}

