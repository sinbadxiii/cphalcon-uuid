
extern zend_class_entry *sparrow_encryption_security_uuid_ce;

ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid);

PHP_METHOD(Sparrow_Encryption_Security_Uuid, mac);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, v1);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, v3);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, v4);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, v5);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, v6);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, parse);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, format);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, hexToDateTime);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, toString);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, getNodeProvider);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, __toString);
PHP_METHOD(Sparrow_Encryption_Security_Uuid, jsonSerialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_mac, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_v1, 0, 0, Sparrow\\Encryption\\Security\\Uuid\\Uuid1, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_v3, 0, 2, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_v4, 0, 0, Sparrow\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_v5, 0, 2, Sparrow\\Encryption\\Security\\Uuid, 0)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_v6, 0, 0, Sparrow\\Encryption\\Security\\Uuid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_parse, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_format, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, version, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sparrow_encryption_security_uuid_hextodatetime, 0, 1, \\DateTimeImmutable, 0)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_encryption_security_uuid_tostring, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_encryption_security_uuid_getnodeprovider, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sparrow_encryption_security_uuid_jsonserialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_encryption_security_uuid_method_entry) {
	PHP_ME(Sparrow_Encryption_Security_Uuid, mac, arginfo_sparrow_encryption_security_uuid_mac, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, v1, arginfo_sparrow_encryption_security_uuid_v1, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, v3, arginfo_sparrow_encryption_security_uuid_v3, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, v4, arginfo_sparrow_encryption_security_uuid_v4, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, v5, arginfo_sparrow_encryption_security_uuid_v5, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, v6, arginfo_sparrow_encryption_security_uuid_v6, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, parse, arginfo_sparrow_encryption_security_uuid_parse, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, format, arginfo_sparrow_encryption_security_uuid_format, ZEND_ACC_PROTECTED)
	PHP_ME(Sparrow_Encryption_Security_Uuid, hexToDateTime, arginfo_sparrow_encryption_security_uuid_hextodatetime, ZEND_ACC_PROTECTED)
	PHP_ME(Sparrow_Encryption_Security_Uuid, toString, arginfo_sparrow_encryption_security_uuid_tostring, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Sparrow_Encryption_Security_Uuid, getNodeProvider, arginfo_sparrow_encryption_security_uuid_getnodeprovider, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Sparrow_Encryption_Security_Uuid, getNodeProvider, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Sparrow_Encryption_Security_Uuid, __toString, arginfo_sparrow_encryption_security_uuid___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Encryption_Security_Uuid, jsonSerialize, arginfo_sparrow_encryption_security_uuid_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
