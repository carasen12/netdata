// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_HTTP_DEFS_H
#define NETDATA_HTTP_DEFS_H

#define HTTP_1_1 " HTTP/1.1"
#define HTTP_HDR_END "\r\n\r\n"
#define HTTP_ENDL "\r\n"

// HTTP_CODES 1XX
#define HTTP_RESP_SWITCH_PROTO 101

// HTTP_CODES 2XX Success
#define HTTP_RESP_OK 200

// HTTP_CODES 3XX Redirections
#define HTTP_RESP_MOVED_PERM 301
#define HTTP_RESP_NOT_MODIFIED 304
#define HTTP_RESP_REDIR_TEMP 307
#define HTTP_RESP_REDIR_PERM 308
#define HTTP_RESP_HTTPS_UPGRADE 399

// HTTP_CODES 4XX Client Errors
#define HTTP_RESP_BAD_REQUEST 400
#define HTTP_RESP_UNAUTHORIZED 401
#define HTTP_RESP_FORBIDDEN 403
#define HTTP_RESP_NOT_FOUND 404
#define HTTP_RESP_METHOD_NOT_ALLOWED 405
#define HTTP_RESP_CONFLICT 409
#define HTTP_RESP_PRECOND_FAIL 412
#define HTTP_RESP_CONTENT_TOO_LONG 413
#define HTTP_RESP_CLIENT_CLOSED_REQUEST 499 // nginx's enxtension to the standard

// HTTP_CODES 5XX Server Errors
#define HTTP_RESP_INTERNAL_SERVER_ERROR 500
#define HTTP_RESP_SERVICE_UNAVAILABLE 503
#define HTTP_RESP_GATEWAY_TIMEOUT 504
#define HTTP_RESP_BACKEND_RESPONSE_INVALID 591

typedef enum __attribute__((__packed__)) {
    HTTP_REQUEST_MODE_NONE      = 0,
    HTTP_REQUEST_MODE_GET       = 1,
    HTTP_REQUEST_MODE_POST      = 2,
    HTTP_REQUEST_MODE_PUT       = 3,
    HTTP_REQUEST_MODE_DELETE    = 4,
    HTTP_REQUEST_MODE_FILECOPY  = 5,
    HTTP_REQUEST_MODE_OPTIONS   = 6,
    HTTP_REQUEST_MODE_STREAM    = 7,
} HTTP_REQUEST_MODE;

const char *http_request_method2string(HTTP_REQUEST_MODE mode);
const char *http_response_code2string(int code);
HTTP_CONTENT_TYPE contenttype_for_filename(const char *filename);

#endif /* NETDATA_HTTP_DEFS_H */
