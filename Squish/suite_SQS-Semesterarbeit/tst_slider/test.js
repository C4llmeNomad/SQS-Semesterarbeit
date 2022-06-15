import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    scrollTo(waitForObject(names.groupBoxSettingsHorizontalSliderSpeedQSlider), 6);
    test.compare(waitForObjectExists(names.groupBoxSettingsLabelSpeedValueQLabel).text, "6");
}
