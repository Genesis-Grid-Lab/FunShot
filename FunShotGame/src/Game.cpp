#include <FunShot.h>

int32_t main(int32_t argc, char** argv) 
{
    using namespace Gen;
    auto app = new Application();
    app->RunContext(true);
    GEN_DELETE(app);
    return 0;
}
