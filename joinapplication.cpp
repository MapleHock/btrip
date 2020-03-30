//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：joinapplication.h
// 当前版本：1.0
// 摘要：本文件中实现抽象类JoinApplication的成员函数的实现
// 作者：吴文绪
// 完成日期：2018.7。27
//****************************************************************************

#include "joinapplication.h"

JoinApplication::JoinApplication(Business& business, Platform& platform,
                                 const QDate& created_date,
                                 JoinApplication::Applicationtype app_type)
  : business_belong_(business),
    platform_belong_(platform),
    created_date_(created_date),
    is_pass_(false),
    application_type_(app_type),
    first_manager_account_(new AbstractUser(business.GetCreditCode(),"btrip")) 
{
  first_manager_account_->BlockAccount();
}

JoinApplication::~JoinApplication() {}

//**********************取值函数***********************************************
Business& JoinApplication::GetBusinessBelong() {
  return business_belong_;
}

Platform& JoinApplication::GetPlatformBelong() {
  return platform_belong_;
}

AbstractUser* JoinApplication::GetFirstAccount() {
  return first_manager_account_;
}

const QDate& JoinApplication::GetCreatedDate() const {
  return created_date_;
}
//****************************************************************************

//*********************设值函数************************************************
bool JoinApplication::IsPass() const {
  return is_pass_;
}

void JoinApplication::ResetFirstAccount(AbstractUser* new_account) {
  delete first_manager_account_;
  first_manager_account_ = new_account;
}

void JoinApplication::Passed() {
  is_pass_ = true;
}