
extern zend_class_entry *phalcon2_0__closure_ce;

ZEPHIR_INIT_CLASS(phalcon2_0__closure);

PHP_METHOD(phalcon2_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon2_0__closure___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, address, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon2_0__closure_method_entry) {
	PHP_ME(phalcon2_0__closure, __invoke, arginfo_phalcon2_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
