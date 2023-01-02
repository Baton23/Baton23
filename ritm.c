#include <ad8232.h> 
#include <time.h> 

int main() 
  // Initialize the AD8232 and configure the gain and filtering settings
  ad8232::init();
  ad8232::setGain(64);
  ad8232::setFilter(0.75);

  while (true) {
    // Read the electrical activity of the heart from the AD8232
    int heart_activity = ad8232::read();

    // Calculate the heart rate from the heart activity data
    int heart_rate = calculateHeartRate(heart_activity);

    // Display the heart rate on the Flipper Zero's screen
    displayHeartRate(heart_rate);

    // Wait for a moment before reading the heart rate again
    sleep(1);
  }

  return 0;
}
