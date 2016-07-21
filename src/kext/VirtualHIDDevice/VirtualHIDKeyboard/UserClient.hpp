#pragma once

#include "VirtualHIDKeyboard.hpp"
#include "hid_report.hpp"
#include "user_client_method.hpp"

class org_pqrs_driver_VirtualHIDKeyboard_UserClient final : public IOUserClient {
  OSDeclareDefaultStructors(org_pqrs_driver_VirtualHIDKeyboard_UserClient);

public:
  virtual bool initWithTask(task_t owningTask, void* securityToken, UInt32 type) override;

  virtual bool start(IOService* provider) override;
  virtual IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments* arguments,
                                  IOExternalMethodDispatch* dispatch = 0, OSObject* target = 0, void* reference = 0) override;

private:
  static IOReturn static_callback_report(org_pqrs_driver_VirtualHIDKeyboard_UserClient* target, void* reference, IOExternalMethodArguments* arguments);
  IOReturn callback_report(const hid_report::keyboard_input& input);

  static IOExternalMethodDispatch methods_[static_cast<size_t>(virtual_hid_keyboard_user_client_method::end_)];
  task_t owner_;
  org_pqrs_driver_VirtualHIDKeyboard* provider_;
};