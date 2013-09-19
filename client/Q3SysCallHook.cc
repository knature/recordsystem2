#include "Q3SysCallHook.h"

Q3SysCallHook::Q3SysCallHook(gameImport_t eventType, Q3SysCallHookExecuteType executeType, std::function<void(Q3SysCallHook *)> callback)
  : eventType_(eventType),
    executeType_(executeType),
    callback_(callback) {
}

Q3SysCallHook::~Q3SysCallHook() {
}

void Q3SysCallHook::reset() {
}


int Q3SysCallHook::getParam(int index) {
	return arg_[index];
}

float Q3SysCallHook::getParamFloat(int index) {
	return (*(float*)&arg_[index]);
}

void *Q3SysCallHook::getParamPtr(int index) {
	return (void *)arg_[index];
}


void Q3SysCallHook::setParam(int index, int arg) {
	arg_[index] = (int)arg;
}

void Q3SysCallHook::setParam(int index, void *arg) {
	arg_[index] = (int)arg;
}

void Q3SysCallHook::setParam(int index, float arg) {
	arg_[index] = *(int *)&arg;
}


int Q3SysCallHook::getReturnArg() {
	return returnValue_;
}

void *Q3SysCallHook::getReturnVMA() {
	return (void *)returnValue_;
}

float Q3SysCallHook::getReturnVMF() {
	return (*(float*)&returnValue_);
}
	

void Q3SysCallHook::setReturnArg(int retArg) {
	returnValue_ = retArg;
}

void Q3SysCallHook::setReturnVMA(void *retPtr) {
	returnValue_ = (int)retPtr;
}

void Q3SysCallHook::setReturnVMF(float retArg) {
	returnValue_ = *(int *)&retArg;
}
