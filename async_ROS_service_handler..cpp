// This implements a non-blocking pattern to fetch data (from a ROS service) without freezing the main execution loop
// Follows "Fire and Poll" strategy. It fires a background task and checks its status every loop iteration without ever halting the main thread


class AsyncLogger {
private:
  std::string current_object_ = "";
  std::future<std::string> object_future_;
public:
  AsyncLogger();

  // Main loop
  void update()
  { 
    // Fire and poll for object we need asynchronously and non-blocking way
    if (!current_object_.empty())
    {
      initializeObject();
    }
  }
  
  // Thread Initializer
  void initializeObject()
  {
    // Launch thread if not only launched
    if (!object_future_.valid())
    {
      // Async returns a std::future
      object_future_ = std::async(std::launch::async, &AsyncLogger::getObject, this);
    }

    // Check for function completion - non-blocking
    if (object_future_.wait_for(std::chrono::seconds(0) == std::future_status::ready)
    {
      try:
      {
        auto name = object_future_.get();
        if (!name.empty) current_object_ = std::move(name);  // Just move the internal pointer from name to current_object_ directly to avoid copying overhead
      }
      catch (const std::exception& e):
      {
        // Logging
        ROS_WARN_STREAM("Object name init failed: " << e.what());
      }
    }
  }
  
  
  // Concurrent function to be run
  void getObject()
  {
    // ROS time-consuming service here for the object
  }

  ~AsyncLogger();
}

