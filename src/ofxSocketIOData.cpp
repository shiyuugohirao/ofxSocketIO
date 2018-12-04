#include "ofxSocketIOData.h"

ofxSocketIOData::ofxSocketIOData () {}

void ofxSocketIOData::setData(sio::message::ptr const& data) {
  _data = data;
}

std::vector<std::shared_ptr<sio::message>>& ofxSocketIOData::getVector() {
  return _data->get_vector();
}

void ofxSocketIOData::setNullData () {
  _data = NULL;
}

/*
 * Would be awesome to use templates here
 */
std::string ofxSocketIOData::getStringValue(std::string key) {
  std::string result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    result = map[key]->get_string();
  } else {
    result = "";
  }
  return result;
}

int ofxSocketIOData::getIntValue(std::string key) {
  int result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    result = map[key]->get_int();
  } else {
    result = NULL;
  }
  return result;
}

float ofxSocketIOData::getFloatValue(std::string key) {
  double result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    result = (float) map[key]->get_double();
  } else {
    result = NULL;
  }
  return result;
}

double ofxSocketIOData::getDoubleValue(std::string key) {
  double result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    result = map[key]->get_double();
  } else {
    result = NULL;
  }
  return result;
}

bool ofxSocketIOData::getBoolValue(std::string key) {
  bool result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    result = map[key]->get_bool();
  } else {
    result = NULL;
  }
  return result;
}

ofxSocketIOData ofxSocketIOData::getNestedValue(std::string key) {
  sio::message::ptr data;
  ofxSocketIOData result;
  auto map = _data->get_map();
  if (_data && map.count(key) > 0) {
    data = map[key];
    result.setData(data);
  } else {
    result.setData(data);
  }
  return result;
}
