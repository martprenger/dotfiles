/* App.c generated by valac 0.56.17, the Vala compiler
 * generated from App.vala, do not modify */

#include <astal-4.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <astal-io.h>
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
enum  {
	APP_0_PROPERTY,
	APP_NUM_PROPERTIES
};
static GParamSpec* app_properties[APP_NUM_PROPERTIES];
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

static gpointer app_parent_class = NULL;
static App* app_instance;
static App* app_instance = NULL;

VALA_EXTERN GType app_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (App, g_object_unref)
static void app_real_request (AstalApplication* base,
                       const gchar* request,
                       GSocketConnection* conn,
                       GError** error);
static void app_real_activate (GApplication* base);
VALA_EXTERN Bar* bar_new (void);
VALA_EXTERN Bar* bar_construct (GType object_type);
VALA_EXTERN GType bar_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Bar, g_object_unref)
static gint app_main (gchar** argv,
               gint argv_length1);
VALA_EXTERN App* app_new (void);
VALA_EXTERN App* app_construct (GType object_type);
static void app_finalize (GObject * obj);
static GType app_get_type_once (void);

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
#line 102 "App.c"
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
#line 6 "../src/vala/App.vala"
	self = (App*) base;
#line 6 "../src/vala/App.vala"
	g_return_if_fail (request != NULL);
#line 6 "../src/vala/App.vala"
	g_return_if_fail (conn != NULL);
#line 7 "../src/vala/App.vala"
	_tmp0_ = string_to_string (request);
#line 7 "../src/vala/App.vala"
	_tmp1_ = g_strconcat ("incoming request: ", _tmp0_, "\n", NULL);
#line 7 "../src/vala/App.vala"
	_tmp2_ = _tmp1_;
#line 7 "../src/vala/App.vala"
	g_print ("%s", _tmp2_);
#line 7 "../src/vala/App.vala"
	_g_free0 (_tmp2_);
#line 9 "../src/vala/App.vala"
	astal_io_write_sock (conn, "response", NULL, NULL);
#line 133 "App.c"
}

static void
app_real_activate (GApplication* base)
{
	App * self;
	Bar* _tmp0_;
	Bar* _tmp1_;
#line 14 "../src/vala/App.vala"
	self = (App*) base;
#line 16 "../src/vala/App.vala"
	astal_application_apply_css ((AstalApplication*) self, "resource:///main.css", FALSE);
#line 17 "../src/vala/App.vala"
	astal_application_apply_css ((AstalApplication*) self, "~/.cache/material/colors.css", FALSE);
#line 20 "../src/vala/App.vala"
	_tmp0_ = bar_new ();
#line 20 "../src/vala/App.vala"
	g_object_ref_sink (_tmp0_);
#line 20 "../src/vala/App.vala"
	_tmp1_ = _tmp0_;
#line 20 "../src/vala/App.vala"
	gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) _tmp1_);
#line 20 "../src/vala/App.vala"
	_g_object_unref0 (_tmp1_);
#line 158 "App.c"
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
#line 172 "App.c"
	}
#line 1254 "glib-2.0.vapi"
	if (str_array != NULL) {
#line 176 "App.c"
		gboolean _tmp1_ = FALSE;
#line 1254 "glib-2.0.vapi"
		if (str_array_length1 > 0) {
#line 1254 "glib-2.0.vapi"
			_tmp1_ = TRUE;
#line 182 "App.c"
		} else {
			gboolean _tmp2_ = FALSE;
#line 1254 "glib-2.0.vapi"
			if (str_array_length1 == -1) {
#line 187 "App.c"
				const gchar* _tmp3_;
#line 1254 "glib-2.0.vapi"
				_tmp3_ = str_array[0];
#line 1254 "glib-2.0.vapi"
				_tmp2_ = _tmp3_ != NULL;
#line 193 "App.c"
			} else {
#line 1254 "glib-2.0.vapi"
				_tmp2_ = FALSE;
#line 197 "App.c"
			}
#line 1254 "glib-2.0.vapi"
			_tmp1_ = _tmp2_;
#line 201 "App.c"
		}
#line 1254 "glib-2.0.vapi"
		_tmp0_ = _tmp1_;
#line 205 "App.c"
	} else {
#line 1254 "glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 209 "App.c"
	}
#line 1254 "glib-2.0.vapi"
	if (_tmp0_) {
#line 213 "App.c"
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
#line 228 "App.c"
		{
			gboolean _tmp4_ = FALSE;
#line 1257 "glib-2.0.vapi"
			i = 0;
#line 1257 "glib-2.0.vapi"
			_tmp4_ = TRUE;
#line 1257 "glib-2.0.vapi"
			while (TRUE) {
#line 237 "App.c"
				gboolean _tmp6_ = FALSE;
				gboolean _tmp7_ = FALSE;
				gint _tmp10_ = 0;
				const gchar* _tmp11_;
#line 1257 "glib-2.0.vapi"
				if (!_tmp4_) {
#line 244 "App.c"
					gint _tmp5_;
#line 1257 "glib-2.0.vapi"
					_tmp5_ = i;
#line 1257 "glib-2.0.vapi"
					i = _tmp5_ + 1;
#line 250 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				_tmp4_ = FALSE;
#line 1257 "glib-2.0.vapi"
				if (str_array_length1 != -1) {
#line 1257 "glib-2.0.vapi"
					_tmp7_ = i < str_array_length1;
#line 258 "App.c"
				} else {
#line 1257 "glib-2.0.vapi"
					_tmp7_ = FALSE;
#line 262 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				if (_tmp7_) {
#line 1257 "glib-2.0.vapi"
					_tmp6_ = TRUE;
#line 268 "App.c"
				} else {
					gboolean _tmp8_ = FALSE;
#line 1257 "glib-2.0.vapi"
					if (str_array_length1 == -1) {
#line 273 "App.c"
						const gchar* _tmp9_;
#line 1257 "glib-2.0.vapi"
						_tmp9_ = str_array[i];
#line 1257 "glib-2.0.vapi"
						_tmp8_ = _tmp9_ != NULL;
#line 279 "App.c"
					} else {
#line 1257 "glib-2.0.vapi"
						_tmp8_ = FALSE;
#line 283 "App.c"
					}
#line 1257 "glib-2.0.vapi"
					_tmp6_ = _tmp8_;
#line 287 "App.c"
				}
#line 1257 "glib-2.0.vapi"
				if (!_tmp6_) {
#line 1257 "glib-2.0.vapi"
					break;
#line 293 "App.c"
				}
#line 1258 "glib-2.0.vapi"
				_tmp11_ = str_array[i];
#line 1258 "glib-2.0.vapi"
				if (_tmp11_ != NULL) {
#line 299 "App.c"
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
#line 311 "App.c"
				} else {
#line 1258 "glib-2.0.vapi"
					_tmp10_ = 0;
#line 315 "App.c"
				}
#line 1258 "glib-2.0.vapi"
				len += (gsize) _tmp10_;
#line 319 "App.c"
			}
		}
#line 1260 "glib-2.0.vapi"
		if (i == 0) {
#line 324 "App.c"
			gchar* _tmp15_;
#line 1261 "glib-2.0.vapi"
			_tmp15_ = g_strdup ("");
#line 1261 "glib-2.0.vapi"
			result = _tmp15_;
#line 1261 "glib-2.0.vapi"
			return result;
#line 332 "App.c"
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
#line 350 "App.c"
			const gchar* _tmp21_;
#line 1267 "glib-2.0.vapi"
			_tmp21_ = str_array[0];
#line 1267 "glib-2.0.vapi"
			_tmp19_ = (const gchar*) _tmp21_;
#line 356 "App.c"
		} else {
#line 1267 "glib-2.0.vapi"
			_tmp19_ = "";
#line 360 "App.c"
		}
#line 1267 "glib-2.0.vapi"
		_tmp22_ = res;
#line 1267 "glib-2.0.vapi"
		_tmp23_ = g_stpcpy ((void*) _tmp22_, _tmp19_);
#line 1267 "glib-2.0.vapi"
		ptr = _tmp23_;
#line 368 "App.c"
		{
			gboolean _tmp24_ = FALSE;
#line 1268 "glib-2.0.vapi"
			i = 1;
#line 1268 "glib-2.0.vapi"
			_tmp24_ = TRUE;
#line 1268 "glib-2.0.vapi"
			while (TRUE) {
#line 377 "App.c"
				void* _tmp26_;
				void* _tmp27_;
				const gchar* _tmp28_ = NULL;
				const gchar* _tmp29_;
				void* _tmp31_;
				void* _tmp32_;
#line 1268 "glib-2.0.vapi"
				if (!_tmp24_) {
#line 386 "App.c"
					gint _tmp25_;
#line 1268 "glib-2.0.vapi"
					_tmp25_ = i;
#line 1268 "glib-2.0.vapi"
					i = _tmp25_ + 1;
#line 392 "App.c"
				}
#line 1268 "glib-2.0.vapi"
				_tmp24_ = FALSE;
#line 1268 "glib-2.0.vapi"
				if (!(i < str_array_length1)) {
#line 1268 "glib-2.0.vapi"
					break;
#line 400 "App.c"
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
#line 412 "App.c"
					const gchar* _tmp30_;
#line 1270 "glib-2.0.vapi"
					_tmp30_ = str_array[i];
#line 1270 "glib-2.0.vapi"
					_tmp28_ = (const gchar*) _tmp30_;
#line 418 "App.c"
				} else {
#line 1270 "glib-2.0.vapi"
					_tmp28_ = "";
#line 422 "App.c"
				}
#line 1270 "glib-2.0.vapi"
				_tmp31_ = ptr;
#line 1270 "glib-2.0.vapi"
				_tmp32_ = g_stpcpy (_tmp31_, _tmp28_);
#line 1270 "glib-2.0.vapi"
				ptr = _tmp32_;
#line 430 "App.c"
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
#line 441 "App.c"
	} else {
		gchar* _tmp34_;
#line 1275 "glib-2.0.vapi"
		_tmp34_ = g_strdup ("");
#line 1275 "glib-2.0.vapi"
		result = _tmp34_;
#line 1275 "glib-2.0.vapi"
		return result;
#line 450 "App.c"
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
#line 25 "../src/vala/App.vala"
	_tmp0_ = g_strdup ("simple-bar");
#line 25 "../src/vala/App.vala"
	_tmp1_ = app_new ();
#line 25 "../src/vala/App.vala"
	astal_io_application_set_instance_name ((AstalIOApplication*) _tmp1_, _tmp0_);
#line 25 "../src/vala/App.vala"
	_g_free0 (_tmp0_);
#line 25 "../src/vala/App.vala"
	_g_object_unref0 (app_instance);
#line 25 "../src/vala/App.vala"
	app_instance = _tmp1_;
#line 475 "App.c"
	{
		App* _tmp2_;
		App* _tmp3_;
#line 29 "../src/vala/App.vala"
		_tmp2_ = app_instance;
#line 29 "../src/vala/App.vala"
		astal_io_application_acquire_socket ((AstalIOApplication*) _tmp2_, &_inner_error0_);
#line 29 "../src/vala/App.vala"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 485 "App.c"
			goto __catch0_g_error;
		}
#line 32 "../src/vala/App.vala"
		_tmp3_ = app_instance;
#line 32 "../src/vala/App.vala"
		result = g_application_run ((GApplication*) _tmp3_, (gint) 0, NULL);
#line 32 "../src/vala/App.vala"
		return result;
#line 494 "App.c"
	}
	goto __finally0;
	__catch0_g_error:
	{
		gint _tmp14_ = -1;
#line 27 "../src/vala/App.vala"
		g_clear_error (&_inner_error0_);
#line 502 "App.c"
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
#line 37 "../src/vala/App.vala"
			_tmp4_ = _vala_g_strjoinv (" ", argv + 1, (gint) (argv_length1 - 1));
#line 37 "../src/vala/App.vala"
			_tmp5_ = _tmp4_;
#line 37 "../src/vala/App.vala"
			_tmp6_ = astal_io_send_request ("simple-bar", _tmp5_, &_inner_error0_);
#line 37 "../src/vala/App.vala"
			_tmp7_ = _tmp6_;
#line 37 "../src/vala/App.vala"
			_g_free0 (_tmp5_);
#line 37 "../src/vala/App.vala"
			response = _tmp7_;
#line 37 "../src/vala/App.vala"
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 527 "App.c"
				goto __catch1_g_error;
			}
#line 41 "../src/vala/App.vala"
			_tmp8_ = response;
#line 41 "../src/vala/App.vala"
			_tmp9_ = string_to_string (_tmp8_);
#line 41 "../src/vala/App.vala"
			_tmp10_ = g_strconcat (_tmp9_, "\n", NULL);
#line 41 "../src/vala/App.vala"
			_tmp11_ = _tmp10_;
#line 41 "../src/vala/App.vala"
			g_print ("%s", _tmp11_);
#line 41 "../src/vala/App.vala"
			_g_free0 (_tmp11_);
#line 42 "../src/vala/App.vala"
			result = 0;
#line 42 "../src/vala/App.vala"
			_g_free0 (response);
#line 42 "../src/vala/App.vala"
			return result;
#line 548 "App.c"
		}
		goto __finally1;
		__catch1_g_error:
		{
			GError* err = NULL;
			GError* _tmp12_;
			const gchar* _tmp13_;
#line 36 "../src/vala/App.vala"
			err = _inner_error0_;
#line 36 "../src/vala/App.vala"
			_inner_error0_ = NULL;
#line 44 "../src/vala/App.vala"
			_tmp12_ = err;
#line 44 "../src/vala/App.vala"
			_tmp13_ = _tmp12_->message;
#line 44 "../src/vala/App.vala"
			g_printerr ("%s", _tmp13_);
#line 45 "../src/vala/App.vala"
			result = 1;
#line 45 "../src/vala/App.vala"
			_g_error_free0 (err);
#line 45 "../src/vala/App.vala"
			return result;
#line 572 "App.c"
		}
		__finally1:
#line 36 "../src/vala/App.vala"
		g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 36 "../src/vala/App.vala"
		g_clear_error (&_inner_error0_);
#line 36 "../src/vala/App.vala"
		return _tmp14_;
#line 581 "App.c"
	}
	__finally0:
#line 27 "../src/vala/App.vala"
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 27 "../src/vala/App.vala"
	g_clear_error (&_inner_error0_);
#line 27 "../src/vala/App.vala"
	return _tmp15_;
#line 590 "App.c"
}

int
main (int argc,
      char ** argv)
{
#line 24 "../src/vala/App.vala"
	return app_main (argv, argc);
#line 599 "App.c"
}

App*
app_construct (GType object_type)
{
	App * self = NULL;
#line 1 "../src/vala/App.vala"
	self = (App*) astal_application_construct (object_type);
#line 1 "../src/vala/App.vala"
	return self;
#line 610 "App.c"
}

App*
app_new (void)
{
#line 1 "../src/vala/App.vala"
	return app_construct (TYPE_APP);
#line 618 "App.c"
}

static void
app_class_init (AppClass * klass,
                gpointer klass_data)
{
#line 1 "../src/vala/App.vala"
	app_parent_class = g_type_class_peek_parent (klass);
#line 1 "../src/vala/App.vala"
	((AstalApplicationClass *) klass)->request = (void (*) (AstalApplication*, const gchar*, GSocketConnection*, GError**)) app_real_request;
#line 1 "../src/vala/App.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) app_real_activate;
#line 1 "../src/vala/App.vala"
	G_OBJECT_CLASS (klass)->finalize = app_finalize;
#line 633 "App.c"
}

static void
app_instance_init (App * self,
                   gpointer klass)
{
}

static void
app_finalize (GObject * obj)
{
	App * self;
#line 1 "../src/vala/App.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_APP, App);
#line 1 "../src/vala/App.vala"
	G_OBJECT_CLASS (app_parent_class)->finalize (obj);
#line 650 "App.c"
}

static GType
app_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (AppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (App), 0, (GInstanceInitFunc) app_instance_init, NULL };
	GType app_type_id;
	app_type_id = g_type_register_static (ASTAL_TYPE_APPLICATION, "App", &g_define_type_info, 0);
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

