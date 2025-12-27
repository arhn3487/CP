package com.company.alumniloginpage;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Pair;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.stream.Collectors;

public class StressTestVisualizer extends Application {
    // UI Components
    private TextArea inputArea;
    private TextArea solutionOutputArea;
    private TextArea bruteOutputArea;
    private TextArea logArea;
    private ProgressBar progressBar;
    private LineChart<Number, Number> executionTimeChart;
    private XYChart.Series<Number, Number> solutionTimeSeries;
    private XYChart.Series<Number, Number> bruteTimeSeries;
    private ComboBox<String> testTypeComboBox;
    private TextField numTestsField;
    private TextField minNField;
    private TextField maxNField;
    private TextField minMField;
    private TextField maxMField;
    private TextField minWeightField;
    private TextField maxWeightField;
    private Button startButton;
    private Button stopButton;
    private ListView<String> failedTestsList;
    private ObservableList<String> failedTests;
    private TabPane mainTabPane;
    private HBox paramRow; // Store paramRow as a class member so it can be accessed easily
    private boolean isRunning = false;
    private AtomicBoolean shouldStop = new AtomicBoolean(false);
    private List<TextField> customParamFields = new ArrayList<>();
    private List<TextField> customParamNames = new ArrayList<>();

    // Path configurations
    private final String GEN_PATH = "C:\\Users\\ASUS\\Desktop\\Practical\\gen.cpp";
    private final String SOLUTION_PATH = "C:\\Users\\ASUS\\Desktop\\Practical\\solution.cpp";
    private final String BRUTE_PATH = "C:\\Users\\ASUS\\Desktop\\Practical\\brute.cpp";
    private final String INPUT_FILE = "input.in";
    private final String SOLUTION_OUTPUT = "output.out";
    private final String BRUTE_OUTPUT = "output2.out";

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Stress Test Visualizer");

        // Create the main layout
        BorderPane mainLayout = new BorderPane();
        mainLayout.setPadding(new Insets(10));

        // Create the main tab pane
        mainTabPane = new TabPane();

        // Create the control panel
        VBox controlPanel = createControlPanel();

        // Create the visualization tab
        Tab visualizationTab = new Tab("Visualization");
        visualizationTab.setContent(createVisualizationPane());
        visualizationTab.setClosable(false);

        // Create the test results tab
        Tab resultsTab = new Tab("Test Results");
        resultsTab.setContent(createResultsPane());
        resultsTab.setClosable(false);

        // Create the custom generator tab
        Tab customGenTab = new Tab("Custom Generator");
        customGenTab.setContent(createCustomGeneratorPane());
        customGenTab.setClosable(false);

        // Add tabs to main tab pane
        mainTabPane.getTabs().addAll(visualizationTab, resultsTab, customGenTab);

        // Set up the main layout
        mainLayout.setTop(controlPanel);
        mainLayout.setCenter(mainTabPane);

        // Create the scene
        Scene scene = new Scene(mainLayout, 1000, 700);
        primaryStage.setScene(scene);
        primaryStage.show();

        // Add window close handler
        primaryStage.setOnCloseRequest(e -> {
            if (isRunning) {
                shouldStop.set(true);
            }
            cleanup();
        });
    }

    private VBox createControlPanel() {
        VBox controlPanel = new VBox(10);
        controlPanel.setPadding(new Insets(10));

        // First row - Test Configuration
        HBox configRow = new HBox(10);

        // Test type selection
        Label testTypeLabel = new Label("Test Type:");
        testTypeComboBox = new ComboBox<>();
        testTypeComboBox.setItems(FXCollections.observableArrayList(
                "Graph Test", "Array Test", "String Test", "Custom Test"));
        testTypeComboBox.setValue("Graph Test");
        testTypeComboBox.setOnAction(e -> updateParamFields());

        // Number of tests
        Label numTestsLabel = new Label("Number of Tests:");
        numTestsField = new TextField("100");
        numTestsField.setPrefWidth(70);

        // Control buttons
        startButton = new Button("Start Tests");
        startButton.setOnAction(e -> startStressTest());

        stopButton = new Button("Stop");
        stopButton.setDisable(true);
        stopButton.setOnAction(e -> shouldStop.set(true));

        // Progress indicator
        progressBar = new ProgressBar(0);
        progressBar.setPrefWidth(150);

        configRow.getChildren().addAll(testTypeLabel, testTypeComboBox, numTestsLabel,
                numTestsField, startButton, stopButton, progressBar);

        // Second row - Parameters
        paramRow = new HBox(10); // Initialize paramRow as a class member

        // Default parameters for Graph test
        minNField = new TextField("5");
        minNField.setPrefWidth(50);

        maxNField = new TextField("20");
        maxNField.setPrefWidth(50);

        minMField = new TextField("10");
        minMField.setPrefWidth(50);

        maxMField = new TextField("50");
        maxMField.setPrefWidth(50);

        minWeightField = new TextField("1");
        minWeightField.setPrefWidth(50);

        maxWeightField = new TextField("100");
        maxWeightField.setPrefWidth(50);

        // Initial parameter row setup
        updateParamFields();

        // Compile state label
        Label compileLabel = new Label("Compilation status: Not compiled");
        Button compileButton = new Button("Compile");
        compileButton.setOnAction(e -> {
            boolean success = compile();
            if (success) {
                compileLabel.setText("Compilation status: Compiled successfully");
                compileLabel.setTextFill(Color.GREEN);
            } else {
                compileLabel.setText("Compilation status: Compilation failed");
                compileLabel.setTextFill(Color.RED);
            }
        });

        HBox compileRow = new HBox(10);
        compileRow.getChildren().addAll(compileButton, compileLabel);

        controlPanel.getChildren().addAll(configRow, paramRow, compileRow);

        return controlPanel;
    }

    private BorderPane createVisualizationPane() {
        BorderPane visualizationPane = new BorderPane();

        // Create chart for execution times
        NumberAxis xAxis = new NumberAxis();
        NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("Test Case");
        yAxis.setLabel("Execution Time (ms)");

        executionTimeChart = new LineChart<>(xAxis, yAxis);
        executionTimeChart.setTitle("Execution Time Comparison");
        executionTimeChart.setCreateSymbols(false);

        solutionTimeSeries = new XYChart.Series<>();
        solutionTimeSeries.setName("Solution");

        bruteTimeSeries = new XYChart.Series<>();
        bruteTimeSeries.setName("Brute Force");

        executionTimeChart.getData().addAll(solutionTimeSeries, bruteTimeSeries);

        // Create log area
        logArea = new TextArea();
        logArea.setEditable(false);
        logArea.setPrefHeight(150);

        // Add chart and log to visualization pane
        visualizationPane.setCenter(executionTimeChart);
        visualizationPane.setBottom(logArea);

        return visualizationPane;
    }

    private BorderPane createResultsPane() {
        BorderPane resultsPane = new BorderPane();

        // Create split pane for the results
        SplitPane splitPane = new SplitPane();

        // Create input and output areas
        VBox inputBox = new VBox(5);
        Label inputLabel = new Label("Input:");
        inputArea = new TextArea();
        inputArea.setEditable(false);
        inputBox.getChildren().addAll(inputLabel, inputArea);

        VBox solutionBox = new VBox(5);
        Label solutionLabel = new Label("Solution Output:");
        solutionOutputArea = new TextArea();
        solutionOutputArea.setEditable(false);
        solutionBox.getChildren().addAll(solutionLabel, solutionOutputArea);

        VBox bruteBox = new VBox(5);
        Label bruteLabel = new Label("Brute Force Output:");
        bruteOutputArea = new TextArea();
        bruteOutputArea.setEditable(false);
        bruteBox.getChildren().addAll(bruteLabel, bruteOutputArea);

        VBox outputsBox = new VBox(10);
        outputsBox.getChildren().addAll(solutionBox, bruteBox);

        splitPane.getItems().addAll(inputBox, outputsBox);
        splitPane.setDividerPositions(0.33);

        // Create failed tests list
        VBox failedTestsBox = new VBox(5);
        Label failedTestsLabel = new Label("Failed Test Cases:");
        failedTests = FXCollections.observableArrayList();
        failedTestsList = new ListView<>(failedTests);
        failedTestsList.setPrefHeight(150);
        failedTestsList.getSelectionModel().selectedItemProperty().addListener(
                (observable, oldValue, newValue) -> {
                    if (newValue != null) {
                        loadFailedTest(newValue);
                    }
                });
        failedTestsBox.getChildren().addAll(failedTestsLabel, failedTestsList);

        resultsPane.setCenter(splitPane);
        resultsPane.setBottom(failedTestsBox);

        return resultsPane;
    }

    private VBox createCustomGeneratorPane() {
        VBox customGenPane = new VBox(10);
        customGenPane.setPadding(new Insets(10));

        Label instructionLabel = new Label("Define custom generator parameters:");

        GridPane paramGrid = new GridPane();
        paramGrid.setHgap(10);
        paramGrid.setVgap(10);
        paramGrid.setPadding(new Insets(10));

        // Add parameter rows
        for (int i = 0; i < 5; i++) {
            Label nameLabel = new Label("Parameter " + (i+1) + " name:");
            TextField nameField = new TextField();
            nameField.setPromptText("e.g. K, MaxValue, etc.");

            Label valueLabel = new Label("Range:");
            TextField valueField = new TextField();
            valueField.setPromptText("min-max");

            paramGrid.add(nameLabel, 0, i);
            paramGrid.add(nameField, 1, i);
            paramGrid.add(valueLabel, 2, i);
            paramGrid.add(valueField, 3, i);

            customParamNames.add(nameField);
            customParamFields.add(valueField);
        }

        TextArea customCodeArea = new TextArea();
        customCodeArea.setPromptText("// Custom generator code template\n" +
                "#include <bits/stdc++.h>\nusing namespace std;\n\n" +
                "int main() {\n" +
                "    // Use parameters defined above\n" +
                "    // Generate your test case here\n" +
                "    return 0;\n}");
        customCodeArea.setPrefHeight(300);

        Button saveButton = new Button("Save Custom Generator");
        saveButton.setOnAction(e -> {
            try {
                Files.write(Paths.get("custom_gen.cpp"), customCodeArea.getText().getBytes());
                log("Custom generator saved to custom_gen.cpp");
            } catch (IOException ex) {
                log("Error saving custom generator: " + ex.getMessage());
            }
        });

        customGenPane.getChildren().addAll(instructionLabel, paramGrid,
                new Label("Custom Generator Code:"), customCodeArea, saveButton);

        return customGenPane;
    }

    private void updateParamFields() {
        String selectedType = testTypeComboBox.getValue();

        // Clear previous parameters
        paramRow.getChildren().clear();

        switch (selectedType) {
            case "Graph Test":
                paramRow.getChildren().addAll(
                        new Label("Min Nodes:"), minNField,
                        new Label("Max Nodes:"), maxNField,
                        new Label("Min Edges:"), minMField,
                        new Label("Max Edges:"), maxMField,
                        new Label("Min Weight:"), minWeightField,
                        new Label("Max Weight:"), maxWeightField
                );
                break;

            case "Array Test":
                paramRow.getChildren().addAll(
                        new Label("Min Size:"), minNField,
                        new Label("Max Size:"), maxNField,
                        new Label("Min Value:"), minWeightField,
                        new Label("Max Value:"), maxWeightField
                );
                break;

            case "String Test":
                paramRow.getChildren().addAll(
                        new Label("Min Length:"), minNField,
                        new Label("Max Length:"), maxNField,
                        new Label("Char Set:"),
                        new ComboBox<>(FXCollections.observableArrayList(
                                "lowercase", "uppercase", "digits", "alphanumeric", "all"))
                );
                break;

            case "Custom Test":
                // Show a message about using the Custom Generator tab
                paramRow.getChildren().add(
                        new Label("Please configure parameters in the Custom Generator tab")
                );
                break;
        }
    }

    private boolean compile() {
        try {
            log("Compiling generator, solution and brute force programs...");

            Process genProcess = new ProcessBuilder("g++", "-std=c++17", "gen.cpp", "-o", GEN_PATH)
                    .redirectErrorStream(true)
                    .start();
            int genExitCode = genProcess.waitFor();

            Process solutionProcess = new ProcessBuilder("g++", "-std=c++17", "solution.cpp", "-o", SOLUTION_PATH)
                    .redirectErrorStream(true)
                    .start();
            int solutionExitCode = solutionProcess.waitFor();

            Process bruteProcess = new ProcessBuilder("g++", "-std=c++17", "brute.cpp", "-o", BRUTE_PATH)
                    .redirectErrorStream(true)
                    .start();
            int bruteExitCode = bruteProcess.waitFor();

            if (genExitCode != 0 || solutionExitCode != 0 || bruteExitCode != 0) {
                log("Compilation failed with exit code(s): gen=" + genExitCode +
                        ", solution=" + solutionExitCode + ", brute=" + bruteExitCode);
                return false;
            }

            log("Compilation successful!");
            return true;
        } catch (IOException | InterruptedException e) {
            log("Compilation error: " + e.getMessage());
            return false;
        }
    }

    private void startStressTest() {
        if (isRunning) {
            log("Test is already running");
            return;
        }

        isRunning = true;
        shouldStop.set(false);
        startButton.setDisable(true);
        stopButton.setDisable(false);

        // Clear previous data
        solutionTimeSeries.getData().clear();
        bruteTimeSeries.getData().clear();
        failedTests.clear();
        inputArea.clear();
        solutionOutputArea.clear();
        bruteOutputArea.clear();

        int numTests = Integer.parseInt(numTestsField.getText());

        new Thread(() -> {
            try {
                for (int i = 1; i <= numTests; i++) {
                    if (shouldStop.get()) {
                        log("Test stopped at test case " + i);
                        break;
                    }

                    // Update progress
                    final int testNum = i;
                    Platform.runLater(() -> {
                        progressBar.setProgress((double) testNum / numTests);
                    });

                    // Generate test case
                    runGenerator();

                    // Run solution
                    long solutionStartTime = System.currentTimeMillis();
                    runSolution();
                    long solutionEndTime = System.currentTimeMillis();
                    long solutionTime = solutionEndTime - solutionStartTime;

                    // Run brute force
                    long bruteStartTime = System.currentTimeMillis();
                    runBrute();
                    long bruteEndTime = System.currentTimeMillis();
                    long bruteTime = bruteEndTime - bruteStartTime;

                    // Add execution times to chart
                    final long finalSolutionTime = solutionTime;
                    final long finalBruteTime = bruteTime;
                    Platform.runLater(() -> {
                        solutionTimeSeries.getData().add(
                                new XYChart.Data<>(testNum, finalSolutionTime));
                        bruteTimeSeries.getData().add(
                                new XYChart.Data<>(testNum, finalBruteTime));
                    });

                    // Check if outputs match
                    if (!compareOutputs()) {
                        String testCaseName = "Test Case " + i;
                        // Save failed test case
                        saveFailedTest(testCaseName, i);

                        // Add to failed tests list
                        Platform.runLater(() -> {
                            failedTests.add(testCaseName);
                            // Switch to results tab to show the difference
                            mainTabPane.getSelectionModel().select(1);
                        });

                        log("Test case " + i + " failed! Check Results tab for details.");
                        break;
                    } else {
                        log("Test case " + i + " passed (Solution: " + solutionTime +
                                "ms, Brute: " + bruteTime + "ms)");
                    }
                }

                if (!shouldStop.get() && failedTests.isEmpty()) {
                    log("All test cases passed successfully!");
                }

                // Reset UI
                Platform.runLater(() -> {
                    startButton.setDisable(false);
                    stopButton.setDisable(true);
                    progressBar.setProgress(1.0);
                });
            } catch (Exception e) {
                log("Error during test: " + e.getMessage());
                Platform.runLater(() -> {
                    startButton.setDisable(false);
                    stopButton.setDisable(true);
                });
            } finally {
                isRunning = false;
            }
        }).start();
    }

    private void runGenerator() throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("./" + GEN_PATH);
        Process process = pb.redirectOutput(new File(INPUT_FILE)).start();
        process.waitFor();
    }

    private void runSolution() throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("./" + SOLUTION_PATH);
        Process process = pb.redirectInput(new File(INPUT_FILE))
                .redirectOutput(new File(SOLUTION_OUTPUT))
                .start();
        process.waitFor();
    }

    private void runBrute() throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("./" + BRUTE_PATH);
        Process process = pb.redirectInput(new File(INPUT_FILE))
                .redirectOutput(new File(BRUTE_OUTPUT))
                .start();
        process.waitFor();
    }

    private boolean compareOutputs() throws IOException {
        List<String> solutionLines = Files.readAllLines(Paths.get(SOLUTION_OUTPUT));
        List<String> bruteLines = Files.readAllLines(Paths.get(BRUTE_OUTPUT));

        // Remove trailing whitespace and normalize line endings
        solutionLines = solutionLines.stream()
                .map(String::trim)
                .collect(Collectors.toList());

        bruteLines = bruteLines.stream()
                .map(String::trim)
                .collect(Collectors.toList());

        return solutionLines.equals(bruteLines);
    }

    private void saveFailedTest(String testName, int testNum) throws IOException {
        // Create a directory for failed tests if it doesn't exist
        Files.createDirectories(Paths.get("failed_tests"));

        // Copy files with test number prefix
        Files.copy(Paths.get(INPUT_FILE),
                Paths.get("failed_tests/" + testNum + "_input.in"));
        Files.copy(Paths.get(SOLUTION_OUTPUT),
                Paths.get("failed_tests/" + testNum + "_solution.out"));
        Files.copy(Paths.get(BRUTE_OUTPUT),
                Paths.get("failed_tests/" + testNum + "_brute.out"));
    }

    private void loadFailedTest(String testName) {
        try {
            int testNum = Integer.parseInt(testName.replaceAll("\\D+", ""));

            String input = new String(Files.readAllBytes(
                    Paths.get("failed_tests/" + testNum + "_input.in")));
            String solutionOutput = new String(Files.readAllBytes(
                    Paths.get("failed_tests/" + testNum + "_solution.out")));
            String bruteOutput = new String(Files.readAllBytes(
                    Paths.get("failed_tests/" + testNum + "_brute.out")));

            Platform.runLater(() -> {
                inputArea.setText(input);
                solutionOutputArea.setText(solutionOutput);
                bruteOutputArea.setText(bruteOutput);
            });
        } catch (IOException e) {
            log("Error loading test case: " + e.getMessage());
        }
    }

    private void log(String message) {
        Platform.runLater(() -> {
            logArea.appendText(message + "\n");
            // Auto-scroll to bottom
            logArea.positionCaret(logArea.getText().length());
        });
    }

    private void cleanup() {
        // Delete temporary files
        try {
            Files.deleteIfExists(Paths.get(INPUT_FILE));
            Files.deleteIfExists(Paths.get(SOLUTION_OUTPUT));
            Files.deleteIfExists(Paths.get(BRUTE_OUTPUT));
        } catch (IOException e) {
            System.err.println("Error cleaning up files: " + e.getMessage());
        }
    }

    // Main method to launch the application
    public static void main(String[] args) {
        // Check for special command
        if (args.length > 0 && args[0].equals("arhn3487")) {
            // Special mode for advanced visualization
            System.out.println("Running in advanced visualization mode");
        }

        launch(args);
    }
}