## https://docs.wxwidgets.org/3.0/overview_helloworld.html

# Main

```cpp
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

```

____
 
 
```cpp
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("UNIX Monitor (Beta)", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}

```
