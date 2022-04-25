/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINMENUVIEWBASE_HPP
#define MAINMENUVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/mainmenu_screen/mainmenuPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class mainmenuViewBase : public touchgfx::View<mainmenuPresenter>
{
public:
    mainmenuViewBase();
    virtual ~mainmenuViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonDecrease_pressed()
    {
        // Override and implement this function in mainmenu
    }

    virtual void buttonIncrease_pressed()
    {
        // Override and implement this function in mainmenu
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image monkeyhead;
    touchgfx::ButtonWithIcon buttonIncrease;
    touchgfx::ButtonWithIcon buttonDecrease;
    touchgfx::TextAreaWithOneWildcard dutyccStatic;
    touchgfx::TextArea tempStatic;
    touchgfx::TextAreaWithOneWildcard tmpDynamic;
    touchgfx::TextAreaWithOneWildcard dutyccDynamic;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<mainmenuViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAINMENUVIEWBASE_HPP