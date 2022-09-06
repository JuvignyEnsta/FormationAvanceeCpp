#include <memory>
#include <iostream>

class GraphicDevice
{
public:
    GraphicDevice() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~GraphicDevice() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Window
{
 public:
    Window( )
        :    m_device(std::make_shared<GraphicDevice>())
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Window( std::shared_ptr<GraphicDevice> t_device )
        :   m_device(t_device)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Window( Window const& win )
        :    m_device(win.m_device)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~Window()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Window& operator = ( Window const & win)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        m_device = win.m_device;
        return *this;
    }

    std::shared_ptr<GraphicDevice> get_device() { return m_device; }
private:
    std::shared_ptr<GraphicDevice> m_device;
};

void displayCopy( Window a_win )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
   auto pt_device = a_win.get_device();
    std::cout << "Fenetre copiee. Nombre de reference sur le device : " << pt_device.use_count() << std::endl;
}

int main()
{
    Window win1;
    auto pt_device = win1.get_device();
    Window win2(pt_device);
    std::cout << "Nombre de references sur le device : " << pt_device.use_count() << std::endl;
    {
    Window win3(win2);
    Window win4, win5;
    win4 = win1;
    std::cout << "Nombre de references sur le device : " << pt_device.use_count() << std::endl;
    }
    std::cout << "Nombre de references sur le device : " << pt_device.use_count() << std::endl;
    displayCopy(win2);
    return EXIT_SUCCESS;    
}

