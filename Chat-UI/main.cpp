#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string

#include "ftxui/component/captured_mouse.hpp"   // for ftxui
#include "ftxui/component/component.hpp"        // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"   // for ComponentBase
#include "ftxui/component/component_options.hpp"// for InputOption
#include "ftxui/component/screen_interactive.hpp"// for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"               // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"                   // for Ref

int main() {
  using namespace ftxui;
  using namespace std;
  // The data:
  string chat_input;

  // The basic input component:
  Component input_chat = Input(&chat_input, " ");

  // The component tree:
  auto component = Container::Vertical({
      input_chat,
  });

  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    return vbox({
               text(" abraxas: "),
               hbox(input_chat->Render()),
           }) |
            border;
  });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
