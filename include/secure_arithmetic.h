#ifndef SECURE_ARITHMETIC_H
#define SECURE_ARITHMETIC_H

#if defined(__cplusplus)
extern "C"
{
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L

#define secure_add(a, b) \
        _Generic(a+b, signed char          :   secure_add_c,      \
                      unsigned char        :   secure_add_uc,     \
                      short                :   secure_add_s,      \
                      unsigned short       :   secure_add_us,     \
                      int                  :   secure_add_i,      \
                      unsigned int         :   secure_add_ui,     \
                      long                 :   secure_add_l,      \
                      unsigned long        :   secure_add_ul,     \
                      long long            :   secure_add_ll,     \
                      unsigned long long   :   secure_add_ull,    \
                      float                :   secure_add_f,      \
                      double               :   secure_add_d,     \
                      long double          :   secure_add_ld    \
                      )(a, b)

#define secure_sub(a, b) \
        _Generic(a-b, signed char          :   secure_sub_c,     \
                      unsigned char        :   secure_sub_uc,    \
                      short                :   secure_sub_s,     \
                      unsigned short       :   secure_sub_us,    \
                      int                  :   secure_sub_i,     \
                      unsigned int         :   secure_sub_ui,    \
                      long                 :   secure_sub_l,     \
                      unsigned long        :   secure_sub_ul,    \
                      long long            :   secure_sub_ll,    \
                      unsigned long long   :   secure_sub_ull,   \
                      float                :   secure_sub_f,     \
                      double               :   secure_sub_d,     \
                      long double          :   secure_sub_ld    \
                      )(a, b)

#define secure_mul(a, b) \
        _Generic(a*b, signed char          :   secure_mul_c,     \
                      unsigned char        :   secure_mul_uc,    \
                      short                :   secure_mul_s,     \
                      unsigned short       :   secure_mul_us,    \
                      int                  :   secure_mul_i,     \
                      unsigned int         :   secure_mul_ui,    \
                      long                 :   secure_mul_l,     \
                      unsigned long        :   secure_mul_ul,    \
                      long long            :   secure_mul_ll,    \
                      unsigned long long   :   secure_mul_ull,   \
                      float                :   secure_mul_f,     \
                      double               :   secure_mul_d,     \
                      long double          :   secure_mul_ld     \
                      )(a, b)

#define secure_div(a, b) \
        _Generic(a/b, signed char          :   secure_div_c,     \
                      unsigned char        :   secure_div_uc,    \
                      short                :   secure_div_s,     \
                      unsigned short       :   secure_div_us,    \
                      int                  :   secure_div_i,     \
                      unsigned int         :   secure_div_ui,    \
                      long                 :   secure_div_l,     \
                      unsigned long        :   secure_div_ul,    \
                      long long            :   secure_div_ll,    \
                      unsigned long long   :   secure_div_ull,   \
                      float                :   secure_div_f,     \
                      double               :   secure_div_d,     \
                      long double          :   secure_div_ld     \
                      )(a, b)

#define secure_mod(a, b) \
        _Generic(a%b, signed char          :   secure_mod_c,     \
                      unsigned char        :   secure_mod_uc,    \
                      short                :   secure_mod_s,     \
                      unsigned short       :   secure_mod_us,    \
                      int                  :   secure_mod_i,     \
                      unsigned int         :   secure_mod_ui,    \
                      long                 :   secure_mod_l,     \
                      unsigned long        :   secure_mod_ul,    \
                      long long            :   secure_mod_ll,    \
                      unsigned long long   :   secure_mod_ull    \
                      )(a, b)

#define secure_neg(a) \
        _Generic(-a, signed char           :   secure_neg_c,     \
                      unsigned char        :   secure_neg_uc,    \
                      short                :   secure_neg_s,     \
                      unsigned short       :   secure_neg_us,    \
                      int                  :   secure_neg_i,     \
                      unsigned int         :   secure_neg_ui,    \
                      long                 :   secure_neg_l,     \
                      unsigned long        :   secure_neg_ul,    \
                      long long            :   secure_neg_ll,    \
                      unsigned long long   :   secure_neg_ull    \
                      )(a)

#endif

//signed char
signed char secure_add_c(signed char const a, signed char const b);
signed char secure_sub_c(signed char const a, signed char const b);
signed char secure_neg_c(signed char const a);
signed char secure_mul_c(signed char const a, signed char const b);
signed char secure_div_c(signed char const a, signed char const b);
signed char secure_mod_c(signed char const a, signed char const b);

//unsigned char
unsigned char secure_add_uc(unsigned char const a, unsigned char const b);
unsigned char secure_sub_uc(unsigned char const a, unsigned char const b);
unsigned char secure_neg_uc(unsigned char const a);
unsigned char secure_mul_uc(unsigned char const a, unsigned char const b);
unsigned char secure_div_uc(unsigned char const a, unsigned char const b);
unsigned char secure_mod_uc(unsigned char const a, unsigned char const b);

//short
short secure_add_s(short const a, short const b);
short secure_sub_s(short const a, short const b);
short secure_neg_s(short const a);
short secure_mul_s(short const a, short const b);
short secure_div_s(short const a, short const b);
short secure_mod_s(short const a, short const b);

//unsigned short
unsigned short secure_add_us(unsigned short const a, unsigned short const b);
unsigned short secure_sub_us(unsigned short const a, unsigned short const b);
unsigned short secure_neg_us(unsigned short const a);
unsigned short secure_mul_us(unsigned short const a, unsigned short const b);
unsigned short secure_div_us(unsigned short const a, unsigned short const b);
unsigned short secure_mod_us(unsigned short const a, unsigned short const b);

// int
int secure_add_i(int const a, int const b);
int secure_sub_i(int const a, int const b);
int secure_neg_i(int const a);
int secure_mul_i(int const a, int const b);
int secure_div_i(int const a, int const b);
int secure_mod_i(int const a, int const b);

//unsigned int
unsigned int secure_add_ui(unsigned int const a, unsigned int const b);
unsigned int secure_sub_ui(unsigned int const a, unsigned int const b);
unsigned int secure_neg_ui(unsigned int const a);
unsigned int secure_mul_ui(unsigned int const a, unsigned int const b);
unsigned int secure_div_ui(unsigned int const a, unsigned int const b);
unsigned int secure_mod_ui(unsigned int const a, unsigned int const b);

//long
long secure_add_l(long const a, long const b);
long secure_sub_l(long const a, long const b);
long secure_neg_l(long const a);
long secure_mul_l(long const a, long const b);
long secure_div_l(long const a, long const b);
long secure_mod_l(long const a, long const b);

//unsigned long
unsigned long secure_add_ul(unsigned long const a, unsigned long const b);
unsigned long secure_sub_ul(unsigned long const a, unsigned long const b);
unsigned long secure_neg_ul(unsigned long const a);
unsigned long secure_mul_ul(unsigned long const a, unsigned long const b);
unsigned long secure_div_ul(unsigned long const a, unsigned long const b);
unsigned long secure_mod_ul(unsigned long const a, unsigned long const b);

//long
long long secure_add_ll(long long const a, long long const b);
long long secure_sub_ll(long long const a, long long const b);
long long secure_neg_ll(long long const a);
long long secure_mul_ll(long long const a, long long const b);
long long secure_div_ll(long long const a, long long const b);
long long secure_mod_ll(long long const a, long long const b);

//unsigned long
unsigned long long secure_add_ull(unsigned long long const a, unsigned long long const b);
unsigned long long secure_sub_ull(unsigned long long const a, unsigned long long const b);
unsigned long long secure_neg_ull(unsigned long long const a);
unsigned long long secure_mul_ull(unsigned long long const a, unsigned long long const b);
unsigned long long secure_div_ull(unsigned long long const a, unsigned long long const b);
unsigned long long secure_mod_ull(unsigned long long const a, unsigned long long const b);

//float
float secure_add_f(float const a, float const b);
float secure_sub_f(float const a, float const b);
float secure_mul_f(float const a, float const b);
float secure_div_f(float const a, float const b);

//double
double secure_add_d(double const a, double const b);
double secure_sub_d(double const a, double const b);
double secure_mul_d(double const a, double const b);
double secure_div_d(double const a, double const b);

//long double
long double secure_add_ld(long double const a, long double const b);
long double secure_sub_ld(long double const a, long double const b);
long double secure_mul_ld(long double const a, long double const b);
long double secure_div_ld(long double const a, long double const b);


#if defined(__cplusplus)
}
#endif

#endif