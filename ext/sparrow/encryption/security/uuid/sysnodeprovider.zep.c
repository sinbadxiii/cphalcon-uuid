
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Sparrow_Encryption_Security_Uuid_SysNodeProvider)
{
	ZEPHIR_REGISTER_CLASS(Sparrow\\Encryption\\Security\\Uuid, SysNodeProvider, sparrow, encryption_security_uuid_sysnodeprovider, sparrow_encryption_security_uuid_sysnodeprovider_method_entry, 0);

	zephir_declare_class_constant_string(sparrow_encryption_security_uuid_sysnodeprovider_ce, SL("IFCONFIG_PATTERN"), "/[^:]([0-9a-f]{2}([:-])[0-9a-f]{2}(\2[0-9a-f]{2}){4})[^:]/i");

	zend_class_implements(sparrow_encryption_security_uuid_sysnodeprovider_ce, 1, sparrow_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Sparrow_Encryption_Security_Uuid_SysNodeProvider, getNode)
{
	zval _13$$5, _16$$10, _26$$10;
	zend_bool _3$$3, _35$$17, _36$$19;
	zval _38;
	zval node, mac, phpOs, _0, _37, _39, addressPaths$$3, _1$$3, _2$$3, macs$$5, addressPath$$5, *_4$$5, _5$$5, _11$$5, _12$$5, _6$$6, _8$$7, _9$$8, _10$$9, disabledFunctions$$10, _14$$10, _15$$10, _17$$10, _18$$10, _19$$10, _20$$10, ifconfig$$10, iface$$10, matches$$10, _25$$10, _27$$10, _28$$10, _29$$10, _30$$10, _31$$10, _21$$12, _22$$13, _23$$14, _24$$15, _32$$16, *_33$$16, _34$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&mac);
	ZVAL_UNDEF(&phpOs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&addressPaths$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&macs$$5);
	ZVAL_UNDEF(&addressPath$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&disabledFunctions$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&ifconfig$$10);
	ZVAL_UNDEF(&iface$$10);
	ZVAL_UNDEF(&matches$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_26$$10);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PHP_OS");
	ZEPHIR_CALL_FUNCTION(&phpOs, "constant", NULL, 56, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_strtoupper(&_0, &phpOs);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "LINUX")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/sys/class/net/*/address");
		ZVAL_LONG(&_2$$3, 4);
		ZEPHIR_CALL_FUNCTION(&addressPaths$$3, "glob", NULL, 57, &_1$$3, &_2$$3);
		zephir_check_call_status();
		_3$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&addressPaths$$3);
		if (!(_3$$3)) {
			_3$$3 = zephir_fast_count_int(&addressPaths$$3) == 0;
		}
		ZEPHIR_INIT_VAR(&node);
		if (_3$$3) {
			ZVAL_STRING(&node, "");
		} else {
			ZEPHIR_INIT_VAR(&macs$$5);
			array_init(&macs$$5);
			zephir_is_iterable(&addressPaths$$3, 0, "sparrow/Encryption/Security/Uuid/SysNodeProvider.zep", 29);
			if (Z_TYPE_P(&addressPaths$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&addressPaths$$3), _4$$5)
				{
					ZEPHIR_INIT_NVAR(&addressPath$$5);
					ZVAL_COPY(&addressPath$$5, _4$$5);
					ZEPHIR_CALL_FUNCTION(&_6$$6, "is_readable", &_7, 58, &addressPath$$5);
					zephir_check_call_status();
					if (zephir_is_true(&_6$$6)) {
						ZEPHIR_INIT_NVAR(&_8$$7);
						zephir_file_get_contents(&_8$$7, &addressPath$$5);
						zephir_array_append(&macs$$5, &_8$$7, PH_SEPARATE, "sparrow/Encryption/Security/Uuid/SysNodeProvider.zep", 25);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &addressPaths$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$5, &addressPaths$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&addressPath$$5, &addressPaths$$3, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_9$$8, "is_readable", &_7, 58, &addressPath$$5);
						zephir_check_call_status();
						if (zephir_is_true(&_9$$8)) {
							ZEPHIR_INIT_NVAR(&_10$$9);
							zephir_file_get_contents(&_10$$9, &addressPath$$5);
							zephir_array_append(&macs$$5, &_10$$9, PH_SEPARATE, "sparrow/Encryption/Security/Uuid/SysNodeProvider.zep", 25);
						}
					ZEPHIR_CALL_METHOD(NULL, &addressPaths$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&addressPath$$5);
			ZEPHIR_INIT_VAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "trim");
			ZEPHIR_CALL_FUNCTION(&_12$$5, "array_map", NULL, 59, &_11$$5, &macs$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&macs$$5, &_12$$5);
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_create_closure_ex(&_11$$5, NULL, sparrow_0__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_12$$5, "array_filter", NULL, 60, &macs$$5, &_11$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&macs$$5, &_12$$5);
			ZEPHIR_MAKE_REF(&macs$$5);
			ZEPHIR_CALL_FUNCTION(&mac, "reset", NULL, 61, &macs$$5);
			ZEPHIR_UNREF(&macs$$5);
			zephir_check_call_status();
			zephir_cast_to_string(&_13$$5, &mac);
			ZEPHIR_CPY_WRT(&node, &_13$$5);
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&node, "")) {
		ZEPHIR_INIT_VAR(&_14$$10);
		ZVAL_STRING(&_14$$10, "disable_functions");
		ZEPHIR_CALL_FUNCTION(&_15$$10, "ini_get", NULL, 62, &_14$$10);
		zephir_check_call_status();
		zephir_cast_to_string(&_16$$10, &_15$$10);
		ZEPHIR_INIT_VAR(&disabledFunctions$$10);
		zephir_fast_strtolower(&disabledFunctions$$10, &_16$$10);
		ZEPHIR_INIT_NVAR(&_14$$10);
		ZVAL_STRING(&_14$$10, "passthru");
		ZEPHIR_CALL_FUNCTION(&_17$$10, "str_contains", NULL, 63, &disabledFunctions$$10, &_14$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_17$$10)) {
			ZVAL_STRING(&node, "");
		}
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 64);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$10);
		ZVAL_LONG(&_18$$10, 0);
		ZVAL_LONG(&_19$$10, 3);
		ZEPHIR_INIT_VAR(&_20$$10);
		zephir_substr(&_20$$10, &phpOs, 0 , 3 , 0);
		zephir_fast_strtoupper(&_14$$10, &_20$$10);
		do {
			if (ZEPHIR_IS_STRING(&_14$$10, "WIN")) {
				ZEPHIR_INIT_VAR(&_21$$12);
				ZVAL_STRING(&_21$$12, "ipconfig /all 2>&1");
				ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 65, &_21$$12);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$10, "DAR")) {
				ZEPHIR_INIT_VAR(&_22$$13);
				ZVAL_STRING(&_22$$13, "ifconfig 2>&1");
				ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 65, &_22$$13);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_14$$10, "FRE")) {
				ZEPHIR_INIT_VAR(&_23$$14);
				ZVAL_STRING(&_23$$14, "netstat -i -f link 2>&1");
				ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 65, &_23$$14);
				zephir_check_call_status();
				break;
			}
			ZEPHIR_INIT_VAR(&_24$$15);
			ZVAL_STRING(&_24$$15, "netstat -ie 2>&1");
			ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 65, &_24$$15);
			zephir_check_call_status();
			break;
		} while(0);

		ZEPHIR_CALL_FUNCTION(&_25$$10, "ob_get_clean", NULL, 66);
		zephir_check_call_status();
		zephir_cast_to_string(&_26$$10, &_25$$10);
		ZEPHIR_CPY_WRT(&ifconfig$$10, &_26$$10);
		ZEPHIR_INIT_VAR(&_27$$10);
		ZVAL_STRING(&_27$$10, "/[^:]([0-9a-f]{2}([:-])[0-9a-f]{2}(\2[0-9a-f]{2}){4})[^:]/i");
		ZVAL_LONG(&_28$$10, 1);
		ZEPHIR_INIT_VAR(&_29$$10);
		ZEPHIR_INIT_VAR(&_30$$10);
		ZVAL_STRING(&_30$$10, "/[^:]([0-9a-f]{2}([:-])[0-9a-f]{2}(\2[0-9a-f]{2}){4})[^:]/i");
		ZVAL_LONG(&_31$$10, 1);
		zephir_preg_match(&_29$$10, &_30$$10, &ifconfig$$10, &matches$$10, 1, zephir_get_intval(&_28$$10) , 0 );
		if (zephir_is_true(&_29$$10)) {
			zephir_array_fetch_long(&_32$$16, &matches$$10, 1, PH_NOISY | PH_READONLY, "sparrow/Encryption/Security/Uuid/SysNodeProvider.zep", 72);
			zephir_is_iterable(&_32$$16, 0, "sparrow/Encryption/Security/Uuid/SysNodeProvider.zep", 77);
			if (Z_TYPE_P(&_32$$16) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_32$$16), _33$$16)
				{
					ZEPHIR_INIT_NVAR(&iface$$10);
					ZVAL_COPY(&iface$$10, _33$$16);
					_35$$17 = !ZEPHIR_IS_STRING_IDENTICAL(&iface$$10, "00:00:00:00:00:00");
					if (_35$$17) {
						_35$$17 = !ZEPHIR_IS_STRING_IDENTICAL(&iface$$10, "00-00-00-00-00-00");
					}
					if (_35$$17) {
						ZEPHIR_CPY_WRT(&node, &iface$$10);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_32$$16, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_34$$16, &_32$$16, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_34$$16)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&iface$$10, &_32$$16, "current", NULL, 0);
					zephir_check_call_status();
						_36$$19 = !ZEPHIR_IS_STRING_IDENTICAL(&iface$$10, "00:00:00:00:00:00");
						if (_36$$19) {
							_36$$19 = !ZEPHIR_IS_STRING_IDENTICAL(&iface$$10, "00-00-00-00-00-00");
						}
						if (_36$$19) {
							ZEPHIR_CPY_WRT(&node, &iface$$10);
						}
					ZEPHIR_CALL_METHOD(NULL, &_32$$16, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&iface$$10);
		}
	}
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_INIT_VAR(&_38);
	zephir_create_array(&_38, 2, 0);
	ZEPHIR_INIT_VAR(&_39);
	ZVAL_STRING(&_39, ":");
	zephir_array_fast_append(&_38, &_39);
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "-");
	zephir_array_fast_append(&_38, &_39);
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "");
	zephir_fast_str_replace(&_37, &_38, &_39, &node);
	ZEPHIR_CPY_WRT(&node, &_37);
	RETURN_CCTOR(&node);
}

