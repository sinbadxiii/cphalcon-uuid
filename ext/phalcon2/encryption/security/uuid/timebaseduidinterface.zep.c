
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Security_Uuid_TimeBasedUidInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon2\\Encryption\\Security\\Uuid, TimeBasedUidInterface, phalcon2, encryption_security_uuid_timebaseduidinterface, phalcon2_encryption_security_uuid_timebaseduidinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon2_Encryption_Security_Uuid_TimeBasedUidInterface, getDateTime);
