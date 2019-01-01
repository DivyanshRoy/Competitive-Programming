str.clear();

compare(); Linear
std::string str1 ("green apple");
  std::string str2 ("red apple");

  if (str1.compare(str2) != 0)
    std::cout << str1 << " is not " << str2 << '\n';

  if (str1.compare(6,5,"apple") == 0)
    std::cout << "still, " << str1 << " is an apple\n";

  if (str2.compare(str2.size()-5,5,"apple") == 0)
    std::cout << "and " << str2 << " is also an apple\n";

  if (str1.compare(6,5,str2,4,5) == 0)
    std::cout << "therefore, both are apples\n";


c_str(); Linear
std::string str ("Please split this sentence into tokens");

  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

  char * p = std::strtok (cstr," ");
  while (p!=0)
  {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
  }

  delete[] cstr;

 empty(); Constant
 str.empty();

 erase(); Linear
 std::string str ("This is an example sentence.");
  std::cout << str << '\n';
                                           // "This is an example sentence."
  str.erase (10,8);                        //            ^^^^^^^^
  std::cout << str << '\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << '\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str << '\n';
                                           // "This sentence."

  += Linear
  std::string name ("John");
  std::string family ("Smith");
  name += " K. ";         // c-string
  name += family;         // string
  name += '\n';           // character

  resize(); Linear
  std::string str ("I like to code in C");
  std::cout << str << '\n';

  unsigned sz = str.size();

  str.resize (sz+2,'+');
  std::cout << str << '\n';

  str.resize (14);
  std::cout << str << '\n';

  size(); Constant
  str.size();


  substr(); Linear
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';


  swap(); Swap two strings in constant time
  std::string buyer ("money");
  std::string seller ("goods");

  std::cout << "Before the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';

  seller.swap (buyer);

  std::cout << " After the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';
