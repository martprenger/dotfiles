/* App.c generated by valac 0.56.18, the Vala compiler
 * generated from App.vala, do not modify */

#include <astal-4.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <astal-io.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#if !defined(VALA_STRICT_C)
#if !defined(__clang__) && defined(__GNUC__) && (__GNUC__ >= 14)
#pragma GCC diagnostic warning "-Wincompatible-pointer-types"
#elif defined(__clang__) && (__clang_major__ >= 16)
#pragma clang diagnostic ignored "-Wincompatible-function-pointer-types"
#pragma clang diagnostic ignored "-Wincompatible-pointer-types"
#endif
#endif
#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define TYPE_APP (app_get_type ())
#define APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APP, App))
#define APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APP, AppClass))
#define IS_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APP))
#define IS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APP))
#define APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APP, AppClass))

typedef struct _App App;
typedef struct _AppClass AppClass;
typedef struct _AppPrivate AppPrivate;

#define TYPE_SCSS (scss_get_type ())
#define SCSS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SCSS, Scss))
#define SCSS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SCSS, ScssClass))
#define IS_SCSS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SCSS))
#define IS_SCSS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SCSS))
#define SCSS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SCSS, ScssClass))

typedef struct _Scss Scss;
typedef struct _ScssClass ScssClass;
enum  {
	APP_0_PROPERTY,
	APP_NUM_PROPERTIES
};
static GParamSpec* app_properties[APP_NUM_PROPERTIES];
#define _scss_unref0(var) ((var == NULL) ? NULL : (var = (scss_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_BAR (bar_get_type ())
#define BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BAR, Bar))
#define BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BAR, BarClass))
#define IS_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BAR))
#define IS_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BAR))
#define BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BAR, BarClass))

typedef struct _Bar Bar;
typedef struct _BarClass BarClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _App {
	AstalApplication parent_instance;
	AppPrivate * priv;
};

struct _AppClass {
	AstalApplicationClass parent_class;
};

struct _AppPrivate {
	Scss* scss;
};

static gint App_private_offset;
static gpointer app_parent_class = NULL;
static App* app_instance;
static App* app_instance = NULL;

VALA_EXTERN GType app_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (App, g_object_unref)
VALA_EXTERN gpointer scss_ref (gpointer instance);
VALA_EXTERN void scss_unref (gpointer instance);
VALA_EXTERN GParamSpec* param_spec_scss (const gchar* name,
                             const gchar* nick,
                             const gchar* blurb,
                             GType object_type,
                             GParamFlags flags);
VALA_EXTERN void value_set_scss (GValue* value,
                     gpointer v_object);
VALA_EXTERN void value_take_scss (GValue* value,
                      gpointer v_object);
VALA_EXTERN gpointer value_get_scss (const GValue* value);
VALA_EXTERN GType scss_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Scss, scss_unref)
static void app_real_request (AstalApplication* base,
                       const gchar* request,
                       GSocketConnection* conn,
                       GError** error);
static void app_real_activate (GApplication* base);
VALA_EXTERN Scss* scss_new (App* _app);
VALA_EXTERN Scss* scss_construct (GType object_type,
                      App* _app);
VALA_EXTERN Bar* bar_new (GdkMonitor* monitor);
VALA_EXTERN Bar* bar_construct (GType object_type,
                    GdkMonitor* monitor);
VALA_EXTERN GType bar_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Bar, g_object_unref)
static gint app_main (gchar** argv,
               gint argv_length1);
VALA_EXTERN App* app_new (void);
VALA_EXTERN App* app_construct (GType object_type);
static void app_finalize (GObject * obj);
static GType app_get_type_once (void);

static inline gpointer
app_get_instance_private (App* self)
{
	return G_STRUCT_MEMBER_P (self, App_private_offset);
}

static const gchar*
string_to_string (const gchar* self)
{
	const gchar* result;
#line 1624 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1625 "glib-2.0.vapi"
	result = self;
#line 1625 "glib-2.0.vapi"
	return result;
#line 143 "App.c"
}

static void
app_real_request (AstalApplication* base,
                  const gchar* request,
                  GSocketConnection* conn,
                  GError** error)
{
	App * self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
#line 8 "../src/vala/App.vala"
	self = (App*) base;
#line 8 "../src/vala/App.vala"
	g_return_if_fail (request != NULL);
#line 8 "../src/vala/App.vala"
	g_return_if_fail (conn != NULL);
#line 9 "../src/vala/App.vala"
	_tmp0_ = string_to_string (request);
#line 9 "../src/vala/App.vala"
	_tmp1_ = g_strconcat ("incoming request: ", _tmp0_, "\n", NULL);
#line 9 "../src/vala/App.vala"
	_tmp2_ = _tmp1_;
#line 9 "../src/vala/App.vala"
	g_print ("%s", _tmp2_);
#line 9 "../src/vala/App.vala"
	_g_free0 (_tmp2_);
#line 10 "../src/vala/App.vala"
	astal_io_write_sock (conn, "response", NULL, NULL);
#line 174 "App.c"
}

static gpointer
_g_object_ref0 (gpointer self)
{
#line 16 "../src/vala/App.vala"
	return self ? g_object_ref (self) : NULL;
#line 182 "App.c"
}

static void
app_real_activate (GApplication* base)
{
	App * self;
	Scss* _tmp0_;
	GList* _tmp1_;
	GList* _tmp2_;
#line 13 "../src/vala/App.vala"
	self = (App*) base;
#line 14 "../src/vala/App.vala"
	_tmp0_ = scss_new (self);
#line 14 "../src/vala/App.vala"
	_scss_unref0 (self->priv->scss);
#line 14 "../src/vala/App.vala"
	self->priv->scss = _tmp0_;
#line 16 "../src/vala/App.vala"
	_tmp1_ = astal_application_get_monitors ((AstalApplication*) self);
#line 16 "../src/vala/App.vala"
	_tmp2_ = _tmp1_;
#line 204 "App.c"
	{
		GList* monitor_collection = NULL;
		GList* monitor_it = NULL;
#line 16 "../src/vala/App.vala"
		monitor_collection = _tmp2_;
#line 16 "../src/vala/App.vala"
		for (monitor_it = monitor_collection; monitor_it != NULL; monitor_it = monitor_it->next) {
#line 212 "App.c"
			GdkMonitor* _tmp3_;
			GdkMonitor* monitor = NULL;
#line 16 "../src/vala/App.vala"
			_tmp3_ = _g_object_ref0 ((GdkMonitor*) monitor_it->data);
#line 16 "../src/vala/App.vala"
			monitor = _tmp3_;
#line 219 "App.c"
			{
				GdkMonitor* _tmp4_;
				Bar* _tmp5_;
				Bar* _tmp6_;
#line 17 "../src/vala/App.vala"
				_tmp4_ = monitor;
#line 17 "../src/vala/App.vala"
				_tmp5_ = bar_new (_tmp4_);
#line 17 "../src/vala/App.vala"
				g_object_ref_sink (_tmp5_);
#line 17 "../src/vala/App.vala"
				_tmp6_ = _tmp5_;
#line 17 "../src/vala/App.vala"
				gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) _tmp6_);
#line 17 "../src/vala/App.vala"
				_g_object_unref0 (_tmp6_);
#line 16 "../src/vala/App.vala"
				_g_object_unref0 (monitor);
#line 238 "App.c"
			}
		}
#line 16 "../src/vala/App.vala"
		(monitor_collection == NULL) ? NULL : (monitor_collection = (g_list_free (monitor_collection), NULL));
#line 243 "App.c"
	}
}

static gchar*
_vala_g_strjoinv (const gchar* separator,
                  gchar** str_array,
                  gint str_array_length1)
{
	gboolean _tmp0_ = FALSE;
	gchar* result;
#line 1251 "glib-2.0.vapi"
	if (separator == NULL) {
#line 1252 "glib-2.0.vapi"
		separator = "";
#line 258 "App.c"
	}
#line 1254 "glib-2.0.vapi"
	if (str_array != NULL) {
#line 262 "App.c"
		gboolean _tmp1_ = FALSE;
#line 1254 "glib-2.0.vapi"
		if (str_array_length1 > 0) {
#line 1254 "glib-2.0.vapi"
			_tmp1_ = TRUE;
#line 268 "App.c"
		} else {
			gboolean _tmp2_ = FALSE;
#line 1254 "glib-2.0.vapi"
			if (str_array_length1 == -1) {
#line 273 "App.c"
				const gchar* _tmp3_;
#line 1254 "glib-2.0.vapi"
				_tmp3_ = str_array[0];
#line 1254 "glib-2.0.vapi"
				_tmp2_ = _tmp3_ != NULL;
#line 279 "App.c"
			} else {
#line 1254 "glib-2.0.vapi"
				_tmp2_ = FALSE;
#line 283 "App.c"
			}
#line 1254 "glib-2.0.vapi"
			_tmp1_ = _tmp2_;
#line 287 "App.c"
		}
#line 1254 "glib-2.0.vapi"
		_tmp0_ = _tmp1_;
#line 291 "App.c"
	} else {
#line 1254 "glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 295 "App.c"
	}
#line 1254 "glib-2.0.vapi"
	if (_tmp0_) {
#line 299 "App.c"
		gint i = 0;
		gsize len = 0UL;
		gint _tmp16_;
		gint _tmp17_;
		const gchar* res = NULL;
		void* _tmp18_;
		const gchar* _tmp19_ = NULL;
		const gchar* _tmp20_;
		void* ptr = NULL;
		const gchar* _tmp22_;
		void* _tmp23_;
		const gchar* _tmp33_;
#line 1256 "glib-2.0.vapi"
		len = (gsize) 1;
#line 314 "App.c"
		{
			gboolean _tmp4_ = FALSE;
#line 1257 "glib-2.0.vapi"
			i = 0;
#line 1257 "glib-2.0.vapi"
			_tmp4_ = TRUE;
#line 1257 "glib-2.0.vapi"
			while (TRUE) {
#line 323 "App.c"
				gboolean _tmp6_ = FALSE;
				gboolean _tmp7_ = FALSE;
				gint _tmp10_ = 0;
				const gchar* _tmp11_;
#line 1257 "glib-2.0.vapi"
				if (!_tmp4_) {
#line 330 "App.c"
					gint _tmp5_;
#line 1257 "glib-2.0.vapi"
					_tmp5_ = i;
#line 1257 "glib-2.0.vapi"
					i = _tmp5_ + 1;
#line 336 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				_tmp4_ = FALSE;
#line 1257 "glib-2.0.vapi"
				if (str_array_length1 != -1) {
#line 1257 "glib-2.0.vapi"
					_tmp7_ = i < str_array_length1;
#line 344 "App.c"
				} else {
#line 1257 "glib-2.0.vapi"
					_tmp7_ = FALSE;
#line 348 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				if (_tmp7_) {
#line 1257 "glib-2.0.vapi"
					_tmp6_ = TRUE;
#line 354 "App.c"
				} else {
					gboolean _tmp8_ = FALSE;
#line 1257 "glib-2.0.vapi"
					if (str_array_length1 == -1) {
#line 359 "App.c"
						const gchar* _tmp9_;
#line 1257 "glib-2.0.vapi"
						_tmp9_ = str_array[i];
#line 1257 "glib-2.0.vapi"
						_tmp8_ = _tmp9_ != NULL;
#line 365 "App.c"
					} else {
#line 1257 "glib-2.0.vapi"
						_tmp8_ = FALSE;
#line 369 "App.c"
					}
#line 1257 "glib-2.0.vapi"
					_tmp6_ = _tmp8_;
#line 373 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				if (!_tmp6_) {
#line 1257 "glib-2.0.vapi"
					break;
#line 379 "App.c"
				}
#line 1258 "glib-2.0.vapi"
				_tmp11_ = str_array[i];
#line 1258 "glib-2.0.vapi"
				if (_tmp11_ != NULL) {
#line 385 "App.c"
					const gchar* _tmp12_;
					gint _tmp13_;
					gint _tmp14_;
#line 1258 "glib-2.0.vapi"
					_tmp12_ = str_array[i];
#line 1258 "glib-2.0.vapi"
					_tmp13_ = strlen ((const gchar*) _tmp12_);
#line 1258 "glib-2.0.vapi"
					_tmp14_ = _tmp13_;
#line 1258 "glib-2.0.vapi"
					_tmp10_ = _tmp14_;
#line 397 "App.c"
				} else {
#line 1258 "glib-2.0.vapi"
					_tmp10_ = 0;
#line 401 "App.c"
				}
#line 1258 "glib-2.0.vapi"
				len += (gsize) _tmp10_;
#line 405 "App.c"
			}
		}
#line 1260 "glib-2.0.vapi"
		if (i == 0) {
#line 410 "App.c"
			gchar* _tmp15_;
#line 1261 "glib-2.0.vapi"
			_tmp15_ = g_strdup ("");
#line 1261 "glib-2.0.vapi"
			result = _tmp15_;
#line 1261 "glib-2.0.vapi"
			return result;
#line 418 "App.c"
		}
#line 1263 "glib-2.0.vapi"
		str_array_length1 = i;
#line 1264 "glib-2.0.vapi"
		_tmp16_ = strlen ((const gchar*) separator);
#line 1264 "glib-2.0.vapi"
		_tmp17_ = _tmp16_;
#line 1264 "glib-2.0.vapi"
		len += (gsize) (_tmp17_ * (i - 1));
#line 1266 "glib-2.0.vapi"
		_tmp18_ = g_malloc (len);
#line 1266 "glib-2.0.vapi"
		res = _tmp18_;
#line 1267 "glib-2.0.vapi"
		_tmp20_ = str_array[0];
#line 1267 "glib-2.0.vapi"
		if (_tmp20_ != NULL) {
#line 436 "App.c"
			const gchar* _tmp21_;
#line 1267 "glib-2.0.vapi"
			_tmp21_ = str_array[0];
#line 1267 "glib-2.0.vapi"
			_tmp19_ = (const gchar*) _tmp21_;
#line 442 "App.c"
		} else {
#line 1267 "glib-2.0.vapi"
			_tmp19_ = "";
#line 446 "App.c"
		}
#line 1267 "glib-2.0.vapi"
		_tmp22_ = res;
#line 1267 "glib-2.0.vapi"
		_tmp23_ = g_stpcpy ((void*) _tmp22_, _tmp19_);
#line 1267 "glib-2.0.vapi"
		ptr = _tmp23_;
#line 454 "App.c"
		{
			gboolean _tmp24_ = FALSE;
#line 1268 "glib-2.0.vapi"
			i = 1;
#line 1268 "glib-2.0.vapi"
			_tmp24_ = TRUE;
#line 1268 "glib-2.0.vapi"
			while (TRUE) {
#line 463 "App.c"
				void* _tmp26_;
				void* _tmp27_;
				const gchar* _tmp28_ = NULL;
				const gchar* _tmp29_;
				void* _tmp31_;
				void* _tmp32_;
#line 1268 "glib-2.0.vapi"
				if (!_tmp24_) {
#line 472 "App.c"
					gint _tmp25_;
#line 1268 "glib-2.0.vapi"
					_tmp25_ = i;
#line 1268 "glib-2.0.vapi"
					i = _tmp25_ + 1;
#line 478 "App.c"
				}
#line 1268 "glib-2.0.vapi"
				_tmp24_ = FALSE;
#line 1268 "glib-2.0.vapi"
				if (!(i < str_array_length1)) {
#line 1268 "glib-2.0.vapi"
					break;
#line 486 "App.c"
				}
#line 1269 "glib-2.0.vapi"
				_tmp26_ = ptr;
#line 1269 "glib-2.0.vapi"
				_tmp27_ = g_stpcpy (_tmp26_, (const gchar*) separator);
#line 1269 "glib-2.0.vapi"
				ptr = _tmp27_;
#line 1270 "glib-2.0.vapi"
				_tmp29_ = str_array[i];
#line 1270 "glib-2.0.vapi"
				if (_tmp29_ != NULL) {
#line 498 "App.c"
					const gchar* _tmp30_;
#line 1270 "glib-2.0.vapi"
					_tmp30_ = str_array[i];
#line 1270 "glib-2.0.vapi"
					_tmp28_ = (const gchar*) _tmp30_;
#line 504 "App.c"
				} else {
#line 1270 "glib-2.0.vapi"
					_tmp28_ = "";
#line 508 "App.c"
				}
#line 1270 "glib-2.0.vapi"
				_tmp31_ = ptr;
#line 1270 "glib-2.0.vapi"
				_tmp32_ = g_stpcpy (_tmp31_, _tmp28_);
#line 1270 "glib-2.0.vapi"
				ptr = _tmp32_;
#line 516 "App.c"
			}
		}
#line 1273 "glib-2.0.vapi"
		_tmp33_ = res;
#line 1273 "glib-2.0.vapi"
		res = NULL;
#line 1273 "glib-2.0.vapi"
		result = (gchar*) _tmp33_;
#line 1273 "glib-2.0.vapi"
		return result;
#line 527 "App.c"
	} else {
		gchar* _tmp34_;
#line 1275 "glib-2.0.vapi"
		_tmp34_ = g_strdup ("");
#line 1275 "glib-2.0.vapi"
		result = _tmp34_;
#line 1275 "glib-2.0.vapi"
		return result;
#line 536 "App.c"
	}
}

static gint
app_main (gchar** argv,
          gint argv_length1)
{
	gchar* _tmp0_;
	App* _tmp1_ = NULL;
	gint _tmp15_ = -1;
	GError* _inner_error0_ = NULL;
	gint result;
#line 24 "../src/vala/App.vala"
	_tmp0_ = g_strdup ("simple-bar");
#line 24 "../src/vala/App.vala"
	_tmp1_ = app_new ();
#line 24 "../src/vala/App.vala"
	astal_io_application_set_instance_name ((AstalIOApplication*) _tmp1_, _tmp0_);
#line 24 "../src/vala/App.vala"
	_g_free0 (_tmp0_);
#line 24 "../src/vala/App.vala"
	_g_object_unref0 (app_instance);
#line 24 "../src/vala/App.vala"
	app_instance = _tmp1_;
#line 561 "App.c"
	{
		App* _tmp2_;
		App* _tmp3_;
#line 26 "../src/vala/App.vala"
		_tmp2_ = app_instance;
#line 26 "../src/vala/App.vala"
		astal_io_application_acquire_socket ((AstalIOApplication*) _tmp2_, &_inner_error0_);
#line 26 "../src/vala/App.vala"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 571 "App.c"
			goto __catch0_g_error;
		}
#line 27 "../src/vala/App.vala"
		_tmp3_ = app_instance;
#line 27 "../src/vala/App.vala"
		result = g_application_run ((GApplication*) _tmp3_, (gint) 0, NULL);
#line 27 "../src/vala/App.vala"
		return result;
#line 580 "App.c"
	}
	goto __finally0;
	__catch0_g_error:
	{
		gint _tmp14_ = -1;
#line 25 "../src/vala/App.vala"
		g_clear_error (&_inner_error0_);
#line 588 "App.c"
		{
			gchar* response = NULL;
			gchar* _tmp4_;
			gchar* _tmp5_;
			gchar* _tmp6_;
			gchar* _tmp7_;
			const gchar* _tmp8_;
			const gchar* _tmp9_;
			gchar* _tmp10_;
			gchar* _tmp11_;
#line 30 "../src/vala/App.vala"
			_tmp4_ = _vala_g_strjoinv (" ", argv + 1, (gint) (argv_length1 - 1));
#line 30 "../src/vala/App.vala"
			_tmp5_ = _tmp4_;
#line 30 "../src/vala/App.vala"
			_tmp6_ = astal_io_send_request ("simple-bar", _tmp5_, &_inner_error0_);
#line 30 "../src/vala/App.vala"
			_tmp7_ = _tmp6_;
#line 30 "../src/vala/App.vala"
			_g_free0 (_tmp5_);
#line 30 "../src/vala/App.vala"
			response = _tmp7_;
#line 30 "../src/vala/App.vala"
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 613 "App.c"
				goto __catch1_g_error;
			}
#line 31 "../src/vala/App.vala"
			_tmp8_ = response;
#line 31 "../src/vala/App.vala"
			_tmp9_ = string_to_string (_tmp8_);
#line 31 "../src/vala/App.vala"
			_tmp10_ = g_strconcat (_tmp9_, "\n", NULL);
#line 31 "../src/vala/App.vala"
			_tmp11_ = _tmp10_;
#line 31 "../src/vala/App.vala"
			g_print ("%s", _tmp11_);
#line 31 "../src/vala/App.vala"
			_g_free0 (_tmp11_);
#line 32 "../src/vala/App.vala"
			result = 0;
#line 32 "../src/vala/App.vala"
			_g_free0 (response);
#line 32 "../src/vala/App.vala"
			return result;
#line 634 "App.c"
		}
		goto __finally1;
		__catch1_g_error:
		{
			GError* err = NULL;
			GError* _tmp12_;
			const gchar* _tmp13_;
#line 29 "../src/vala/App.vala"
			err = _inner_error0_;
#line 29 "../src/vala/App.vala"
			_inner_error0_ = NULL;
#line 34 "../src/vala/App.vala"
			_tmp12_ = err;
#line 34 "../src/vala/App.vala"
			_tmp13_ = _tmp12_->message;
#line 34 "../src/vala/App.vala"
			g_printerr ("%s", _tmp13_);
#line 35 "../src/vala/App.vala"
			result = 1;
#line 35 "../src/vala/App.vala"
			_g_error_free0 (err);
#line 35 "../src/vala/App.vala"
			return result;
#line 658 "App.c"
		}
		__finally1:
#line 29 "../src/vala/App.vala"
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 29 "../src/vala/App.vala"
		g_clear_error (&_inner_error0_);
#line 29 "../src/vala/App.vala"
		return _tmp14_;
#line 667 "App.c"
	}
	__finally0:
#line 25 "../src/vala/App.vala"
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 25 "../src/vala/App.vala"
	g_clear_error (&_inner_error0_);
#line 25 "../src/vala/App.vala"
	return _tmp15_;
#line 676 "App.c"
}

int
main (int argc,
      char ** argv)
{
#line 23 "../src/vala/App.vala"
	return app_main (argv, argc);
#line 685 "App.c"
}

App*
app_construct (GType object_type)
{
	App * self = NULL;
#line 3 "../src/vala/App.vala"
	self = (App*) astal_application_construct (object_type);
#line 3 "../src/vala/App.vala"
	return self;
#line 696 "App.c"
}

App*
app_new (void)
{
#line 3 "../src/vala/App.vala"
	return app_construct (TYPE_APP);
#line 704 "App.c"
}

static void
app_class_init (AppClass * klass,
                gpointer klass_data)
{
#line 3 "../src/vala/App.vala"
	app_parent_class = g_type_class_peek_parent (klass);
#line 3 "../src/vala/App.vala"
	g_type_class_adjust_private_offset (klass, &App_private_offset);
#line 3 "../src/vala/App.vala"
	((AstalApplicationClass *) klass)->request = (void (*) (AstalApplication*, const gchar*, GSocketConnection*, GError**)) app_real_request;
#line 3 "../src/vala/App.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) app_real_activate;
#line 3 "../src/vala/App.vala"
	G_OBJECT_CLASS (klass)->finalize = app_finalize;
#line 721 "App.c"
}

static void
app_instance_init (App * self,
                   gpointer klass)
{
#line 3 "../src/vala/App.vala"
	self->priv = app_get_instance_private (self);
#line 730 "App.c"
}

static void
app_finalize (GObject * obj)
{
	App * self;
#line 3 "../src/vala/App.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_APP, App);
#line 6 "../src/vala/App.vala"
	_scss_unref0 (self->priv->scss);
#line 3 "../src/vala/App.vala"
	G_OBJECT_CLASS (app_parent_class)->finalize (obj);
#line 743 "App.c"
}

static GType
app_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (AppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (App), 0, (GInstanceInitFunc) app_instance_init, NULL };
	GType app_type_id;
	app_type_id = g_type_register_static (ASTAL_TYPE_APPLICATION, "App", &g_define_type_info, 0);
	App_private_offset = g_type_add_instance_private (app_type_id, sizeof (AppPrivate));
	return app_type_id;
}

GType
app_get_type (void)
{
	static volatile gsize app_type_id__once = 0;
	if (g_once_init_enter (&app_type_id__once)) {
		GType app_type_id;
		app_type_id = app_get_type_once ();
		g_once_init_leave (&app_type_id__once, app_type_id);
	}
	return app_type_id__once;
}

