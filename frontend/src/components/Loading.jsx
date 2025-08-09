export default function Loading() {
  return (
    <div
      role="status"
      style={{
        display: "inline-block",
        width: 40,
        height: 40,
        border: "4px solid lightgray",
        borderTop: "4px solid blue",
        borderRadius: "50%",
        animation: "spin 1s linear infinite",
      }}
    >
      <style>{`
        @keyframes spin {
          0% { transform: rotate(0deg);}
          100% { transform: rotate(360deg);}
        }
      `}</style>
      <span style={{
        position: "absolute",
        width: 1,
        height: 1,
        padding: 0,
        overflow: "hidden",
        clip: "rect(0,0,0,0)",
        whiteSpace: "nowrap",
        border: 0,
      }}>Loading...</span>
    </div>
  );
}
