#ifndef BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_BASE_HPP_20111008
#define BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_BASE_HPP_20111008

// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/function.hpp>
#include <boost/range/iterator_range.hpp>

namespace boost { namespace asio {

class io_service;

}  // namespace asio

}  // namespace boost

namespace boost { namespace network { namespace http {

struct client_base_pimpl;
struct request;
struct response;

class request_options;

class client_options;

struct client_base {
  typedef
    function<void(boost::iterator_range<char const *> const &, system::error_code const &)>
    body_callback_function_type;

  client_base();
  explicit client_base(client_options const &options);
  ~client_base();
  response const request_skeleton(request const & request_,
                                  std::string const & method,
                                  bool get_body,
                                  body_callback_function_type callback,
                                  request_options const &options);
  void clear_resolved_cache();
 private:
  client_base_pimpl * pimpl;
};
  
} /* http */
  
} /* network */
  
} /* boost */

#endif /* BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_BASE_HPP_20111008 */
