/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Cluster_STUB_DEFAULT_HPP_
#define V1_COMMONAPI_Cluster_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v1/commonapi/ClusterStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace commonapi {

/**
 * Provides a default implementation for ClusterStubRemoteEvent and
 * ClusterStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT ClusterStubDefault
    : public virtual ClusterStub {
public:
    COMMONAPI_EXPORT ClusterStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(Cluster::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT ClusterStubRemoteEvent* initStubAdapter(const std::shared_ptr< ClusterStubAdapter> &_adapter) {
        CommonAPI::Stub<ClusterStubAdapter, ClusterStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const bool &getErrrorCheckAttribute() {
        return errrorCheckAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const bool &getErrrorCheckAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getErrrorCheckAttribute();
    }
    COMMONAPI_EXPORT virtual void setErrrorCheckAttribute(bool _value) {
        const bool valueChanged = trySetErrrorCheckAttribute(std::move(_value));
        if (valueChanged) {
            fireErrrorCheckAttributeChanged(errrorCheckAttributeValue_);
        }
    }
    COMMONAPI_EXPORT virtual void sendImage1(const std::shared_ptr<CommonAPI::ClientId> _client, std::vector< uint8_t > _image1) {
        (void)_client;
        (void)_image1;
    }
    COMMONAPI_EXPORT virtual void sendImage2(const std::shared_ptr<CommonAPI::ClientId> _client, std::vector< uint8_t > _image2) {
        (void)_client;
        (void)_image2;
    }
    COMMONAPI_EXPORT virtual void sendImage3(const std::shared_ptr<CommonAPI::ClientId> _client, std::vector< uint8_t > _image3) {
        (void)_client;
        (void)_image3;
    }
    COMMONAPI_EXPORT virtual void sendImage4(const std::shared_ptr<CommonAPI::ClientId> _client, std::vector< uint8_t > _image4) {
        (void)_client;
        (void)_image4;
    }
    COMMONAPI_EXPORT virtual void fireErrorBroadcastEvent(const int32_t &_result) {
        ClusterStub::fireErrorBroadcastEvent(_result);
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetErrrorCheckAttribute(bool _value) {
        if (!validateErrrorCheckAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<ClusterStubAdapter> stubAdapter = CommonAPI::Stub<ClusterStubAdapter, ClusterStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockErrrorCheckAttribute(true);
            valueChanged = (errrorCheckAttributeValue_ != _value);
            errrorCheckAttributeValue_ = std::move(_value);
            stubAdapter->lockErrrorCheckAttribute(false);
        } else {
            valueChanged = (errrorCheckAttributeValue_ != _value);
            errrorCheckAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateErrrorCheckAttributeRequestedValue(const bool &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual ClusterStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(ClusterStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        ClusterStubDefault *defaultStub_;
    };
protected:
    ClusterStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    bool errrorCheckAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Cluster_STUB_DEFAULT