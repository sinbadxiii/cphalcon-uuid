
extern zend_class_entry *phalcon2_encryption_crypt_padding_noop_ce;

ZEPHIR_INIT_CLASS(Phalcon2_Encryption_Crypt_Padding_Noop);

PHP_METHOD(Phalcon2_Encryption_Crypt_Padding_Noop, pad);
PHP_METHOD(Phalcon2_Encryption_Crypt_Padding_Noop, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_crypt_padding_noop_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon2_encryption_crypt_padding_noop_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_encryption_crypt_padding_noop_method_entry) {
	PHP_ME(Phalcon2_Encryption_Crypt_Padding_Noop, pad, arginfo_phalcon2_encryption_crypt_padding_noop_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon2_Encryption_Crypt_Padding_Noop, unpad, arginfo_phalcon2_encryption_crypt_padding_noop_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
