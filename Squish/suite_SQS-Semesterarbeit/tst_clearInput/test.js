import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    mouseClick(waitForObject(names.groupBoxInputTextEditInputQTextEdit), 100, 83, Qt.NoModifier, Qt.LeftButton);
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "test ");
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "<NumPad1>");
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "<NumPad2>");
    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), "<NumPad3>");
    test.compare(waitForObjectExists(names.groupBoxInputTextEditInputQTextEdit).plainText, "test 123");
    clickButton(waitForObject(names.groupBoxSettingsPushButtonClearInputQPushButton));
    test.compare(waitForObjectExists(names.groupBoxInputTextEditInputQTextEdit).plainText, "");
}
