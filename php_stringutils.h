/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_STRINGUTILS_H
#define PHP_STRINGUTILS_H

extern zend_module_entry stringutils_module_entry;
#define phpext_stringutils_ptr &stringutils_module_entry

#define PHP_STRINGUTILS_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_STRINGUTILS_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_STRINGUTILS_API __attribute__ ((visibility("default")))
#else
#	define PHP_STRINGUTILS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(stringutils);
PHP_MSHUTDOWN_FUNCTION(stringutils);
PHP_RINIT_FUNCTION(stringutils);
PHP_RSHUTDOWN_FUNCTION(stringutils);
PHP_MINFO_FUNCTION(stringutils);

PHP_FUNCTION(str_check_encoding);
PHP_FUNCTION(str_scrub);
PHP_FUNCTION(len);
PHP_FUNCTION(str_to_array);
PHP_FUNCTION(str_each_char);
PHP_FUNCTION(str_take_while);
PHP_FUNCTION(str_drop_while);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(stringutils)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(stringutils)
*/

/* In every utility function you add that needs to use variables 
   in php_stringutils_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as STRINGUTILS_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define STRINGUTILS_G(v) TSRMG(stringutils_globals_id, zend_stringutils_globals *, v)
#else
#define STRINGUTILS_G(v) (stringutils_globals.v)
#endif

#endif	/* PHP_STRINGUTILS_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
