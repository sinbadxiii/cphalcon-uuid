
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_NodeProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Sparrow\\Encryption\\Security\\Uuid, NodeProviderInterface, sparrow, encryption_security_uuid_nodeproviderinterface, sparrow_encryption_security_uuid_nodeproviderinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Sparrow_Encryption_Security_Uuid_NodeProviderInterface, getNode);
