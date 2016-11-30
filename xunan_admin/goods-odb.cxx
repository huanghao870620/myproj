// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "goods-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/simple-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // goods
  //

  struct access::object_traits_impl< ::goods, id_mysql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mysql::connection&,
      image_type&,
      id_image_type&,
      mysql::binding&,
      mysql::binding&)
    {
    }
  };

  access::object_traits_impl< ::goods, id_mysql >::id_type
  access::object_traits_impl< ::goods, id_mysql >::
  id (const id_image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::goods, id_mysql >::id_type
  access::object_traits_impl< ::goods, id_mysql >::
  id (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::goods, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = 0;

    // name_
    //
    if (t[1UL])
    {
      i.name_value.capacity (i.name_size);
      grew = true;
    }

    // info_
    //
    if (t[2UL])
    {
      i.info_value.capacity (i.info_size);
      grew = true;
    }

    // capacity_
    //
    t[3UL] = 0;

    // lowest_price_
    //
    t[4UL] = 0;

    // highest_price_
    //
    t[5UL] = 0;

    // purchasing_position_
    //
    if (t[6UL])
    {
      i.purchasing_position_value.capacity (i.purchasing_position_size);
      grew = true;
    }

    // date_of_production_
    //
    if (t[7UL])
    {
      i.date_of_production_value.capacity (i.date_of_production_size);
      grew = true;
    }

    // bar_code_
    //
    if (t[8UL])
    {
      i.bar_code_value.capacity (i.bar_code_size);
      grew = true;
    }

    // speed_awb_
    //
    if (t[9UL])
    {
      i.speed_awb_value.capacity (i.speed_awb_size);
      grew = true;
    }

    // goods_according_to_positive_
    //
    t[10UL] = 0;

    // left_photo_
    //
    t[11UL] = 0;

    // right_photo_
    //
    t[12UL] = 0;

    // goods_invoice_
    //
    t[13UL] = 0;

    // express_single_
    //
    t[14UL] = 0;

    // state
    //
    t[15UL] = 0;

    // add_time_
    //
    if (t[16UL])
    {
      i.add_time_value.capacity (i.add_time_size);
      grew = true;
    }

    // classid_
    //
    t[17UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // name_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.name_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.name_value.capacity ());
    b[n].length = &i.name_size;
    b[n].is_null = &i.name_null;
    n++;

    // info_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.info_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.info_value.capacity ());
    b[n].length = &i.info_size;
    b[n].is_null = &i.info_null;
    n++;

    // capacity_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.capacity_value;
    b[n].is_null = &i.capacity_null;
    n++;

    // lowest_price_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.lowest_price_value;
    b[n].is_null = &i.lowest_price_null;
    n++;

    // highest_price_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.highest_price_value;
    b[n].is_null = &i.highest_price_null;
    n++;

    // purchasing_position_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.purchasing_position_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.purchasing_position_value.capacity ());
    b[n].length = &i.purchasing_position_size;
    b[n].is_null = &i.purchasing_position_null;
    n++;

    // date_of_production_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.date_of_production_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.date_of_production_value.capacity ());
    b[n].length = &i.date_of_production_size;
    b[n].is_null = &i.date_of_production_null;
    n++;

    // bar_code_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.bar_code_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.bar_code_value.capacity ());
    b[n].length = &i.bar_code_size;
    b[n].is_null = &i.bar_code_null;
    n++;

    // speed_awb_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.speed_awb_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.speed_awb_value.capacity ());
    b[n].length = &i.speed_awb_size;
    b[n].is_null = &i.speed_awb_null;
    n++;

    // goods_according_to_positive_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.goods_according_to_positive_value;
    b[n].is_null = &i.goods_according_to_positive_null;
    n++;

    // left_photo_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.left_photo_value;
    b[n].is_null = &i.left_photo_null;
    n++;

    // right_photo_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.right_photo_value;
    b[n].is_null = &i.right_photo_null;
    n++;

    // goods_invoice_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.goods_invoice_value;
    b[n].is_null = &i.goods_invoice_null;
    n++;

    // express_single_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.express_single_value;
    b[n].is_null = &i.express_single_null;
    n++;

    // state
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.state_value;
    b[n].is_null = &i.state_null;
    n++;

    // add_time_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.add_time_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.add_time_value.capacity ());
    b[n].length = &i.add_time_size;
    b[n].is_null = &i.add_time_null;
    n++;

    // classid_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.classid_value;
    b[n].is_null = &i.classid_null;
    n++;
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::goods, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // id_
    //
    if (sk == statement_insert)
    {
      long unsigned int const& v =
        o.id_;

      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, v);
      i.id_null = is_null;
    }

    // name_
    //
    {
      // From goods.h:43:12
      ::std::string const& v =
        o.name_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.name_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.name_value,
        size,
        is_null,
        v);
      i.name_null = is_null;
      i.name_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.name_value.capacity ());
    }

    // info_
    //
    {
      ::std::string const& v =
        o.info_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.info_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.info_value,
        size,
        is_null,
        v);
      i.info_null = is_null;
      i.info_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.info_value.capacity ());
    }

    // capacity_
    //
    {
      long int const& v =
        o.capacity_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.capacity_value, is_null, v);
      i.capacity_null = is_null;
    }

    // lowest_price_
    //
    {
      long int const& v =
        o.lowest_price_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.lowest_price_value, is_null, v);
      i.lowest_price_null = is_null;
    }

    // highest_price_
    //
    {
      long int const& v =
        o.highest_price_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.highest_price_value, is_null, v);
      i.highest_price_null = is_null;
    }

    // purchasing_position_
    //
    {
      ::std::string const& v =
        o.purchasing_position_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.purchasing_position_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.purchasing_position_value,
        size,
        is_null,
        v);
      i.purchasing_position_null = is_null;
      i.purchasing_position_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.purchasing_position_value.capacity ());
    }

    // date_of_production_
    //
    {
      ::std::string const& v =
        o.date_of_production_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.date_of_production_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.date_of_production_value,
        size,
        is_null,
        v);
      i.date_of_production_null = is_null;
      i.date_of_production_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.date_of_production_value.capacity ());
    }

    // bar_code_
    //
    {
      ::std::string const& v =
        o.bar_code_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.bar_code_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.bar_code_value,
        size,
        is_null,
        v);
      i.bar_code_null = is_null;
      i.bar_code_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.bar_code_value.capacity ());
    }

    // speed_awb_
    //
    {
      ::std::string const& v =
        o.speed_awb_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.speed_awb_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.speed_awb_value,
        size,
        is_null,
        v);
      i.speed_awb_null = is_null;
      i.speed_awb_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.speed_awb_value.capacity ());
    }

    // goods_according_to_positive_
    //
    {
      long int const& v =
        o.goods_according_to_positive_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.goods_according_to_positive_value, is_null, v);
      i.goods_according_to_positive_null = is_null;
    }

    // left_photo_
    //
    {
      long int const& v =
        o.left_photo_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.left_photo_value, is_null, v);
      i.left_photo_null = is_null;
    }

    // right_photo_
    //
    {
      long int const& v =
        o.right_photo_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.right_photo_value, is_null, v);
      i.right_photo_null = is_null;
    }

    // goods_invoice_
    //
    {
      long int const& v =
        o.goods_invoice_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.goods_invoice_value, is_null, v);
      i.goods_invoice_null = is_null;
    }

    // express_single_
    //
    {
      long int const& v =
        o.express_single_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.express_single_value, is_null, v);
      i.express_single_null = is_null;
    }

    // state
    //
    {
      int const& v =
        o.state;

      bool is_null (false);
      mysql::value_traits<
          int,
          mysql::id_long >::set_image (
        i.state_value, is_null, v);
      i.state_null = is_null;
    }

    // add_time_
    //
    {
      ::std::string const& v =
        o.add_time_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.add_time_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.add_time_value,
        size,
        is_null,
        v);
      i.add_time_null = is_null;
      i.add_time_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.add_time_value.capacity ());
    }

    // classid_
    //
    {
      long int const& v =
        o.classid_;

      bool is_null (false);
      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_image (
        i.classid_value, is_null, v);
      i.classid_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      long unsigned int& v =
        o.id_;

      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.id_value,
        i.id_null);
    }

    // name_
    //
    {
      // From goods.h:43:23
      ::std::string& v =
        o.name_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.name_value,
        i.name_size,
        i.name_null);
    }

    // info_
    //
    {
      ::std::string& v =
        o.info_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.info_value,
        i.info_size,
        i.info_null);
    }

    // capacity_
    //
    {
      long int& v =
        o.capacity_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.capacity_value,
        i.capacity_null);
    }

    // lowest_price_
    //
    {
      long int& v =
        o.lowest_price_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.lowest_price_value,
        i.lowest_price_null);
    }

    // highest_price_
    //
    {
      long int& v =
        o.highest_price_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.highest_price_value,
        i.highest_price_null);
    }

    // purchasing_position_
    //
    {
      ::std::string& v =
        o.purchasing_position_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.purchasing_position_value,
        i.purchasing_position_size,
        i.purchasing_position_null);
    }

    // date_of_production_
    //
    {
      ::std::string& v =
        o.date_of_production_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.date_of_production_value,
        i.date_of_production_size,
        i.date_of_production_null);
    }

    // bar_code_
    //
    {
      ::std::string& v =
        o.bar_code_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.bar_code_value,
        i.bar_code_size,
        i.bar_code_null);
    }

    // speed_awb_
    //
    {
      ::std::string& v =
        o.speed_awb_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.speed_awb_value,
        i.speed_awb_size,
        i.speed_awb_null);
    }

    // goods_according_to_positive_
    //
    {
      long int& v =
        o.goods_according_to_positive_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.goods_according_to_positive_value,
        i.goods_according_to_positive_null);
    }

    // left_photo_
    //
    {
      long int& v =
        o.left_photo_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.left_photo_value,
        i.left_photo_null);
    }

    // right_photo_
    //
    {
      long int& v =
        o.right_photo_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.right_photo_value,
        i.right_photo_null);
    }

    // goods_invoice_
    //
    {
      long int& v =
        o.goods_invoice_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.goods_invoice_value,
        i.goods_invoice_null);
    }

    // express_single_
    //
    {
      long int& v =
        o.express_single_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.express_single_value,
        i.express_single_null);
    }

    // state
    //
    {
      int& v =
        o.state;

      mysql::value_traits<
          int,
          mysql::id_long >::set_value (
        v,
        i.state_value,
        i.state_null);
    }

    // add_time_
    //
    {
      ::std::string& v =
        o.add_time_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.add_time_value,
        i.add_time_size,
        i.add_time_null);
    }

    // classid_
    //
    {
      long int& v =
        o.classid_;

      mysql::value_traits<
          long int,
          mysql::id_longlong >::set_value (
        v,
        i.classid_value,
        i.classid_null);
    }
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::goods, id_mysql >::persist_statement[] =
  "INSERT INTO `goods` "
  "(`id`, "
  "`name`, "
  "`info`, "
  "`capacity`, "
  "`lowest_price`, "
  "`highest_price`, "
  "`purchasing_position`, "
  "`date_of_production`, "
  "`bar_code`, "
  "`speed_awb`, "
  "`goods_according_to_positive`, "
  "`left_photo`, "
  "`right_photo`, "
  "`goods_invoice`, "
  "`express_single`, "
  "`state`, "
  "`add_time`, "
  "`classid`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::goods, id_mysql >::find_statement[] =
  "SELECT "
  "`goods`.`id`, "
  "`goods`.`name`, "
  "`goods`.`info`, "
  "`goods`.`capacity`, "
  "`goods`.`lowest_price`, "
  "`goods`.`highest_price`, "
  "`goods`.`purchasing_position`, "
  "`goods`.`date_of_production`, "
  "`goods`.`bar_code`, "
  "`goods`.`speed_awb`, "
  "`goods`.`goods_according_to_positive`, "
  "`goods`.`left_photo`, "
  "`goods`.`right_photo`, "
  "`goods`.`goods_invoice`, "
  "`goods`.`express_single`, "
  "`goods`.`state`, "
  "`goods`.`add_time`, "
  "`goods`.`classid` "
  "FROM `goods` "
  "WHERE `goods`.`id`=?";

  const char access::object_traits_impl< ::goods, id_mysql >::update_statement[] =
  "UPDATE `goods` "
  "SET "
  "`name`=?, "
  "`info`=?, "
  "`capacity`=?, "
  "`lowest_price`=?, "
  "`highest_price`=?, "
  "`purchasing_position`=?, "
  "`date_of_production`=?, "
  "`bar_code`=?, "
  "`speed_awb`=?, "
  "`goods_according_to_positive`=?, "
  "`left_photo`=?, "
  "`right_photo`=?, "
  "`goods_invoice`=?, "
  "`express_single`=?, "
  "`state`=?, "
  "`add_time`=?, "
  "`classid`=? "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::goods, id_mysql >::erase_statement[] =
  "DELETE FROM `goods` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::goods, id_mysql >::query_statement[] =
  "SELECT "
  "`goods`.`id`, "
  "`goods`.`name`, "
  "`goods`.`info`, "
  "`goods`.`capacity`, "
  "`goods`.`lowest_price`, "
  "`goods`.`highest_price`, "
  "`goods`.`purchasing_position`, "
  "`goods`.`date_of_production`, "
  "`goods`.`bar_code`, "
  "`goods`.`speed_awb`, "
  "`goods`.`goods_according_to_positive`, "
  "`goods`.`left_photo`, "
  "`goods`.`right_photo`, "
  "`goods`.`goods_invoice`, "
  "`goods`.`express_single`, "
  "`goods`.`state`, "
  "`goods`.`add_time`, "
  "`goods`.`classid` "
  "FROM `goods`";

  const char access::object_traits_impl< ::goods, id_mysql >::erase_query_statement[] =
  "DELETE FROM `goods`";

  const char access::object_traits_impl< ::goods, id_mysql >::table_name[] =
  "`goods`";

  void access::object_traits_impl< ::goods, id_mysql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im.id_value = 0;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.id_ = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.id_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::goods, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::goods, id_mysql >::pointer_type
  access::object_traits_impl< ::goods, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::goods, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::goods, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.id_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::goods, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::goods, id_mysql >::object_type >
  access::object_traits_impl< ::goods, id_mysql >::
  query (database&, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mysql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::goods, id_mysql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
