#include <node.h>
#include <v8.h>

extern "C" {
#ifdef _XOPEN_SOURCE
  #include <unistd.h>
#endif
#ifdef _GNU_SOURCE
  #include <crypt.h>
#endif
}

using namespace v8;

#ifdef _XOPEN_SOURCE
Handle<Value> crypt(const Arguments& args) {
  HandleScope scope;
  if (args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  } 
  if (!args[0]->IsString() || !args[1]->IsString()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }
  return scope.Close(String::New(crypt(
    *String::AsciiValue(args[0]),
    *String::AsciiValue(args[1])
  )));
}
#endif

void init(Handle<Object> exports) {
#ifdef _XOPEN_SOURCE
  exports->Set(
    String::NewSymbol("crypt"),
    FunctionTemplate::New(crypt)->GetFunction()
  );
#endif
}

NODE_MODULE(unix_crypt, init)
