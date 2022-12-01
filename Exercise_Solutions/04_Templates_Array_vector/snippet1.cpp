/*
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass var;
 ...
}
*/

/*
The templated class CMyClass is called without specifying the type.
Moreover, there is a semi-colon missing after the class definition
*/
template <typename T>
class CMyClass{
  T a;
  T b;
};

int main(){
  CMyClass<int> var;
}