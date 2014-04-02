#include <node.h>
#include <v8.h>

extern "C" {
  #include <unistd.h>
}

using namespace v8;

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

void init(Handle<Object> exports) {
  exports->Set(
    String::NewSymbol("crypt"),
    FunctionTemplate::New(crypt)->GetFunction()
  );
}

NODE_MODULE(unix_crypt, init)
