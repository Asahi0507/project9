// -*- C++ -*-
/*!
 * @file  JudgeAccele.cpp
 * @brief 受け取った加速度センサーのデータ型を変換して出力する
 * @date $Date$
 *
 * @author Tae MITSUFUJI<cy17261@shibaura-it.ac.jp>
 *
 * $Id$
 */

#include "JudgeAccele.h"

// Module specification
// <rtc-template block="module_spec">
static const char* judgeaccele_spec[] =
  {
    "implementation_id", "JudgeAccele",
    "type_name",         "JudgeAccele",
    "description",       "受け取った加速度センサーのデータ型を変換して出力する",
    "version",           "1.0.0",
    "vendor",            "TaeMITSUFUJI",
    "category",          "accept",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
JudgeAccele::JudgeAccele(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_HotmockAcceleIn("HotmockAccele", m_HotmockAccele),
    m_AcceleNumberOut("AcceleNumber", m_AcceleNumber)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
JudgeAccele::~JudgeAccele()
{
}



RTC::ReturnCode_t JudgeAccele::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("HotmockAccele", m_HotmockAcceleIn);
  
  // Set OutPort buffer
  addOutPort("AcceleNumber", m_AcceleNumberOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudgeAccele::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAccele::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAccele::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t JudgeAccele::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t JudgeAccele::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

#include<cstdlib>

RTC::ReturnCode_t JudgeAccele::onExecute(RTC::UniqueId ec_id)
{
	{
		if (m_HotmockAcceleIn.isNew()){
			m_HotmockAcceleIn.read();
			std::cout << "読み込みました" ;
			if (std::abs(m_HotmockAccele.data[0])> std::abs(m_HotmockAccele.data[1])&& std::abs(m_HotmockAccele.data[0]) >std::abs(m_HotmockAccele.data[2]) && std::abs(m_HotmockAccele.data[0]) >3 ) {
				m_AcceleNumber.data = 0;
				m_AcceleNumberOut.write();
				std::cout << "X送ります";
			}
			else if (std::abs(m_HotmockAccele.data[1]) > std::abs(m_HotmockAccele.data[0]) && std::abs(m_HotmockAccele.data[1]) > std::abs(m_HotmockAccele.data[2]) && std::abs(m_HotmockAccele.data[1]) > 3) {
				m_AcceleNumber.data = 1;
				m_AcceleNumberOut.write();
				std::cout << "Y";
			}
			else if (std::abs(m_HotmockAccele.data[2])> std::abs(m_HotmockAccele.data[0])&& std::abs(m_HotmockAccele.data[2]) > std::abs(m_HotmockAccele.data[1] )&& std::abs(m_HotmockAccele.data[2]) > 3) {
				m_AcceleNumber.data = 2;
				m_AcceleNumberOut.write();
				std::cout << "Z送ります";
			}
			else return RTC::RTC_OK;;
		}
	}
	return RTC::RTC_OK;
}



RTC::ReturnCode_t JudgeAccele::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t JudgeAccele::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAccele::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAccele::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t JudgeAccele::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void JudgeAcceleInit(RTC::Manager* manager)
  {
    coil::Properties profile(judgeaccele_spec);
    manager->registerFactory(profile,
                             RTC::Create<JudgeAccele>,
                             RTC::Delete<JudgeAccele>);
  }
  
};


