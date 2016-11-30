// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef GOODS_ODB_HXX
#define GOODS_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "goods.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // goods
  //
  template <>
  struct class_traits< ::goods >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::goods >
  {
    public:
    typedef ::goods object_type;
    typedef ::goods* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // goods
  //
  template <typename A>
  struct query_columns< ::goods, id_mysql, A >
  {
    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    id_type_;

    static const id_type_ id;

    // name
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    name_type_;

    static const name_type_ name;

    // info
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    info_type_;

    static const info_type_ info;

    // capacity
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    capacity_type_;

    static const capacity_type_ capacity;

    // lowest_price
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    lowest_price_type_;

    static const lowest_price_type_ lowest_price;

    // highest_price
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    highest_price_type_;

    static const highest_price_type_ highest_price;

    // purchasing_position
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    purchasing_position_type_;

    static const purchasing_position_type_ purchasing_position;

    // date_of_production
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    date_of_production_type_;

    static const date_of_production_type_ date_of_production;

    // bar_code
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    bar_code_type_;

    static const bar_code_type_ bar_code;

    // speed_awb
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    speed_awb_type_;

    static const speed_awb_type_ speed_awb;

    // goods_according_to_positive
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    goods_according_to_positive_type_;

    static const goods_according_to_positive_type_ goods_according_to_positive;

    // left_photo
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    left_photo_type_;

    static const left_photo_type_ left_photo;

    // right_photo
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    right_photo_type_;

    static const right_photo_type_ right_photo;

    // goods_invoice
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    goods_invoice_type_;

    static const goods_invoice_type_ goods_invoice;

    // express_single
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    express_single_type_;

    static const express_single_type_ express_single;

    // state
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    state_type_;

    static const state_type_ state;

    // add_time
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    add_time_type_;

    static const add_time_type_ add_time;

    // classid
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    classid_type_;

    static const classid_type_ classid;

    // adv_pic
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    adv_pic_type_;

    static const adv_pic_type_ adv_pic;
  };

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::id_type_
  query_columns< ::goods, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::name_type_
  query_columns< ::goods, id_mysql, A >::
  name (A::table_name, "`name`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::info_type_
  query_columns< ::goods, id_mysql, A >::
  info (A::table_name, "`info`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::capacity_type_
  query_columns< ::goods, id_mysql, A >::
  capacity (A::table_name, "`capacity`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::lowest_price_type_
  query_columns< ::goods, id_mysql, A >::
  lowest_price (A::table_name, "`lowest_price`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::highest_price_type_
  query_columns< ::goods, id_mysql, A >::
  highest_price (A::table_name, "`highest_price`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::purchasing_position_type_
  query_columns< ::goods, id_mysql, A >::
  purchasing_position (A::table_name, "`purchasing_position`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::date_of_production_type_
  query_columns< ::goods, id_mysql, A >::
  date_of_production (A::table_name, "`date_of_production`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::bar_code_type_
  query_columns< ::goods, id_mysql, A >::
  bar_code (A::table_name, "`bar_code`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::speed_awb_type_
  query_columns< ::goods, id_mysql, A >::
  speed_awb (A::table_name, "`speed_awb`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::goods_according_to_positive_type_
  query_columns< ::goods, id_mysql, A >::
  goods_according_to_positive (A::table_name, "`goods_according_to_positive`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::left_photo_type_
  query_columns< ::goods, id_mysql, A >::
  left_photo (A::table_name, "`left_photo`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::right_photo_type_
  query_columns< ::goods, id_mysql, A >::
  right_photo (A::table_name, "`right_photo`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::goods_invoice_type_
  query_columns< ::goods, id_mysql, A >::
  goods_invoice (A::table_name, "`goods_invoice`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::express_single_type_
  query_columns< ::goods, id_mysql, A >::
  express_single (A::table_name, "`express_single`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::state_type_
  query_columns< ::goods, id_mysql, A >::
  state (A::table_name, "`state`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::add_time_type_
  query_columns< ::goods, id_mysql, A >::
  add_time (A::table_name, "`add_time`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::classid_type_
  query_columns< ::goods, id_mysql, A >::
  classid (A::table_name, "`classid`", 0);

  template <typename A>
  const typename query_columns< ::goods, id_mysql, A >::adv_pic_type_
  query_columns< ::goods, id_mysql, A >::
  adv_pic (A::table_name, "`adv_pic`", 0);

  template <typename A>
  struct pointer_query_columns< ::goods, id_mysql, A >:
    query_columns< ::goods, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::goods, id_mysql >:
    public access::object_traits< ::goods >
  {
    public:
    struct id_image_type
    {
      unsigned long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      unsigned long long id_value;
      my_bool id_null;

      // name_
      //
      details::buffer name_value;
      unsigned long name_size;
      my_bool name_null;

      // info_
      //
      details::buffer info_value;
      unsigned long info_size;
      my_bool info_null;

      // capacity_
      //
      long long capacity_value;
      my_bool capacity_null;

      // lowest_price_
      //
      long long lowest_price_value;
      my_bool lowest_price_null;

      // highest_price_
      //
      long long highest_price_value;
      my_bool highest_price_null;

      // purchasing_position_
      //
      details::buffer purchasing_position_value;
      unsigned long purchasing_position_size;
      my_bool purchasing_position_null;

      // date_of_production_
      //
      details::buffer date_of_production_value;
      unsigned long date_of_production_size;
      my_bool date_of_production_null;

      // bar_code_
      //
      details::buffer bar_code_value;
      unsigned long bar_code_size;
      my_bool bar_code_null;

      // speed_awb_
      //
      details::buffer speed_awb_value;
      unsigned long speed_awb_size;
      my_bool speed_awb_null;

      // goods_according_to_positive_
      //
      long long goods_according_to_positive_value;
      my_bool goods_according_to_positive_null;

      // left_photo_
      //
      long long left_photo_value;
      my_bool left_photo_null;

      // right_photo_
      //
      long long right_photo_value;
      my_bool right_photo_null;

      // goods_invoice_
      //
      long long goods_invoice_value;
      my_bool goods_invoice_null;

      // express_single_
      //
      long long express_single_value;
      my_bool express_single_null;

      // state
      //
      int state_value;
      my_bool state_null;

      // add_time_
      //
      details::buffer add_time_value;
      unsigned long add_time_size;
      my_bool add_time_null;

      // classid_
      //
      long long classid_value;
      my_bool classid_null;

      // adv_pic_
      //
      long long adv_pic_value;
      my_bool adv_pic_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 19UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::goods, id_common >:
    public access::object_traits_impl< ::goods, id_mysql >
  {
  };

  // goods
  //
}

#include "goods-odb.ixx"

#include <odb/post.hxx>

#endif // GOODS_ODB_HXX
