type subscription;

type event('a) =
  {
    ..
    "endCoordinates": {
      .
      "height": float,
      "screenX": float,
      "screenY": float,
      "width": float,
    },
  } as 'a;

type listener('a) = event('a) => unit;

type keyboardEvent =
  | KeyboardWillShow
  | KeyboardDidShow
  | KeyboardWillHide
  | KeyboardDidHide
  | KeyboardWillChangeFrame
  | KeyboardDidChangeFrame;

let mapKeyboardEvent = keyboardEvent =>
  switch (keyboardEvent) {
  | KeyboardWillShow => "keyboardWillShow"
  | KeyboardDidShow => "keyboardDidShow"
  | KeyboardWillHide => "keyboardWillHide"
  | KeyboardDidHide => "keyboardDidHide"
  | KeyboardWillChangeFrame => "keyboardWillChangeFrame"
  | KeyboardDidChangeFrame => "keyboardDidChangeFrame"
  };

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _addListener : (string, listener('a)) => subscription =
  "addListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss : unit => unit = "";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _removeAllListeners : string => unit = "removeAllListeners";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _removeListener : (string, listener('a)) => unit = "removeListener";

let addListener = (keyboardEvent, listener) =>
  _addListener(mapKeyboardEvent(keyboardEvent), listener);

let removeAllListeners = keyboardEvent =>
  _removeAllListeners(mapKeyboardEvent(keyboardEvent));

let removeListener = (keyboardEvent, listener) =>
  _removeListener(mapKeyboardEvent(keyboardEvent), listener);

module Subscription = {
  [@bs.send.pipe: subscription] external remove : unit = "";
};
