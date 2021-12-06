#include <iostream>

#ifdef SYSTEM_WINDOWS
  #include <windows.h>
#endif

#include <gluten.h>

#include "IntroWindow.h"

using namespace std;
using namespace Gluten;

void safe_main(int argc, char* argv[])
{
  IntroWindow* introWindow = NULL;
  Path::initialize(argc, argv);
  Core core(argc, argv);

  core.setSize(800, 600);
  core.setTitle("Wavefront Animation Studio");

  if(argc > 1)
  {
    try
    {
      core.add(new ModelWindow(&core, std::string(argv[1])));
    }
    catch(exception& e)
    {
      core.add(new TestWindow(&core));
      new Gluten::MessageBox(&core, e.what());
    }
  }
  else
  {
    core.add(new IntroWindow(&core));
  }

  core.run();
}

int main(int argc, char* argv[])
{
#ifdef SYSTEM_WINDOWS
  FreeConsole();
#endif

  try
  {
    safe_main(argc, argv);

    return 0;
  }
  catch(exception& e)
  {
    cout << "Exception: " << e.what() << endl;

    return 1;
  }
}
