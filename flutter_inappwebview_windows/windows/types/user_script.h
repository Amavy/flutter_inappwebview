#ifndef FLUTTER_INAPPWEBVIEW_PLUGIN_USER_SCRIPT_H_
#define FLUTTER_INAPPWEBVIEW_PLUGIN_USER_SCRIPT_H_

#include <flutter/standard_method_codec.h>
#include <optional>
#include <string>
#include <vector>

#include "../utils/flutter.h"

namespace flutter_inappwebview_plugin
{
  enum UserScriptInjectionTime {
    atDocumentStart = 0,
    atDocumentEnd
  };

  class UserScript
  {
  public:
    std::wstring id;
    const std::optional<std::string> groupName;
    const std::string source;
    const UserScriptInjectionTime injectionTime;
    const std::vector<std::string> allowedOriginRules;

    UserScript(
      const std::optional<std::string>& groupName,
      const std::string& source,
      const UserScriptInjectionTime& injectionTime,
      const std::vector<std::string>& allowedOriginRules
    );
    UserScript(const flutter::EncodableMap& map);
    ~UserScript();
  };
}
#endif //FLUTTER_INAPPWEBVIEW_PLUGIN_USER_SCRIPT_H_